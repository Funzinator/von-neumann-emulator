#include <QRegExp>
#include <QString>
#include <iostream>
#include <map>

#define PARSE_REGEXP "^\\s*([0-9]+)\\s*:\\s*((NGA|FNG|NOT|INR|INI|INB|OUR|OUI|OUB|IRE|RIN|ENTIER|NOP|STP|HLT|SRR)|((ENA\\s+[0-9]+)|(ENAR\\s+[0-9]*(\\.[0-9]+)?))|((ENAI|ENIA|ADI|SBI)(,I)?\\s+[0-9]+)|(ENI(,I)?\\s+[0-9]+\\s*,\\s*[0-9]+)|((LDA|STA|ADA|SBA|MUA|DVA|MDA|FAD|FSB|FMU|FDV|AND|OR|XOR|UJP|AZJ,GR|AZJ,GE|AZJ,LS|AZJ,LE|AZJ,EQ|AZJ,NE|SRJ)((,I)?\\s+[0-9]+|\\s+[0-9]+\\s*,\\s*[0-9]+)))\\s*(\\{([^\\}])*\\}\\s*)*$"
#define SPLIT_REGEXP "\\s*([0-9]+)\\s*:\\s*([a-zA-Z]{3,6})(,I)?(\\s*([0-9]+\\.?[0-9]*)\\s*(,\\s*([0-9]+))?)?\\s*((\\{([^\\}])*\\}\\s*)*)"

using namespace std;

struct RawOperation
{
    unsigned int LineNumber;
    QString Operator;
    QString Param1;
    QString Param2;
    QString Comment;
    bool indirect;
    
    void show()
    {
        cout << "Line Number: " << this->LineNumber << endl;
        cout << "Operator   : " << this->Operator.toStdString() << endl;
        cout << "indirect   : " << (this->indirect ? "true" : "false") << endl;
        cout << "Parameter 1: " << this->Param1.toStdString() << endl;
        cout << "Parameter 2: " << this->Param2.toStdString() << endl;
        cout << "Comment    : " << this->Comment.toStdString() << endl;
    }
};

union Storage
{
    int i;
    double f;
};

class StorageCell
{
private:
    Storage values;
public:
    StorageCell()
    {
        this->values.i = this->values.f = 0;
    }

    void setInt(int i) { this->values.i = i; }
    void setFloat(double f) { this->values.f = f; }

    int getInt() { return this->values.i; }
    double getFloat() { return this->values.f; }
};

class Configuration
{
private:
    StorageCell *AC; /* Akkumulator       */
    unsigned int PC; /* Befehlszähler     */
    unsigned int SR; /* Subroutine-Zeiger */
    map<unsigned int,StorageCell *> Data;
    map<unsigned int,StorageCell *> IndexRegister;
    
public:
    Configuration()
    {
        this->AC = new StorageCell;
        this->PC = 0;
        this->SR = 0;
    }

    StorageCell* getAC() { return this->AC; }
    unsigned int getPC() { return this->PC; }
    unsigned int getSR() { return this->SR; }

    StorageCell* getData(unsigned int x)
    {
        if (this->Data[x] == 0)
        {
            this->Data[x] = new StorageCell;
        }

        return this->Data[x];
    }

    StorageCell* getIndexRegister(unsigned int x)
    {
        if (this->IndexRegister[x] == 0)
        {
            this->IndexRegister[x] = new StorageCell;
        }

        return this->IndexRegister[x];
    }

    void setPC(unsigned int i) { this->PC = i; }
    void setSR(unsigned int i) { this->SR = i; }
    
    /* Setter-Funktionen für StorageCells werden nicht benötigt,
     * da ->getAC()->setInt() benutzt werden kann.
     */     
};

class Operation
{
protected:
    StorageCell *Param1;
    StorageCell *Param2;
    bool indirect;
    QString Operatorname;
    QString Comment;
    
public:
    Operation(RawOperation *rawOp)
    {
        this->indirect     = rawOp->indirect;
        this->Operatorname = rawOp->Operator;
        this->Comment      = rawOp->Comment;

        /* just to be safe */
        this->Param1 = 0;
        this->Param2 = 0;
    }
    
    virtual void run(Configuration *c) = 0;
};

class BinaryOperation : public Operation
{
public:
    BinaryOperation(RawOperation *rawOp) : Operation(rawOp)
    {
        /* nothing to do here */
    }
};

class ENA : public BinaryOperation
{
public:
    ENA(RawOperation *rawOp) : BinaryOperation(rawOp)
    {
        /* Dank ENAR kann ich erst hier die Parameter setzen */
        this->Param1 = new StorageCell;
        this->Param1->setInt(rawOp->Param1.toInt());
    }

    void run(Configuration *c)
    {
        c->getAC()->setInt(this->Param1->getInt());
        c->setPC(c->getPC() + 1);
    }
};

class ENAR : public BinaryOperation
{
public:
    ENAR(RawOperation *rawOp) : BinaryOperation(rawOp)
    {
        /* Dank ENAR kann ich erst hier die Parameter setzen */
        this->Param1 = new StorageCell;
        this->Param1->setFloat(rawOp->Param1.toFloat());
    }

    void run(Configuration *c)
    {
        c->getAC()->setFloat(this->Param1->getFloat());
        c->setPC(c->getPC() + 1);
    }
};

class Parser
{
private:
    QRegExp *ParseRegExp;
    QRegExp *SplitRegExp;

    bool validateLine(QString line)
    {
        return this->ParseRegExp->exactMatch(line);
    }

public:
    Parser()
    {
        this->ParseRegExp = new QRegExp(PARSE_REGEXP);
        this->SplitRegExp = new QRegExp(SPLIT_REGEXP);
    }

    ~Parser()
    {
        delete this->ParseRegExp;
        delete this->SplitRegExp;
    }
        
    RawOperation* convertLine(QString line)
    {
        RawOperation *res = new RawOperation;

        if (this->validateLine(line))
        {
            this->SplitRegExp->indexIn(line);

            res->LineNumber = this->SplitRegExp->cap(1).toInt();
            res->Operator   = this->SplitRegExp->cap(2);
            res->Param1     = this->SplitRegExp->cap(5);
            res->Param2     = this->SplitRegExp->cap(7);
            res->Comment    = this->SplitRegExp->cap(8);
            res->indirect   = (this->SplitRegExp->cap(3).toStdString() == ",I" ? true : false);

            return res;
        }
        else
        {
            return 0;
        }
    }
};

int main(int argc, char *argv[])
{
    Parser p;
    RawOperation *x = 0;
    
    if ((x = p.convertLine(argv[1])))
    {
        x->show();
    }
    
    return 0;
}
