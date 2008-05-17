#include <QRegExp>
#include <QString>
#include <iostream>

using namespace std;

class RawOperation
{
public:
    /* FIXME: make private! */
    unsigned long int LineNumber;
    QString Operator;
    bool indirect;
    QString Param1; /* QString, weil in einem Fall (ENAR) ein double */
    QString Param2;
    QString Comment;

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

class Parser
{
private:
	QRegExp *_RegExp;

	bool _validateLine(QString line)
	{
        return this->_RegExp->exactMatch(line);
	}

public:	
	Parser()
	{
        this->_RegExp = new QRegExp("^\\s*([0-9]+)\\s*:\\s*((NGA|FNG|NOT|INR|INI|INB|OUR|OUI|OUB|IRE|RIN|ENTIER|NOP|STP|HLT|SRR)|((ENA\\s+[0-9]+)|(ENAR\\s+[0-9]*(\\.[0-9]+)?))|((ENAI|ENIA|ADI|SBI)(,I)?\\s+[0-9]+)|(ENI(,I)?\\s+[0-9]+\\s*,\\s*[0-9]+)|((LDA|STA|ADA|SBA|MUA|DVA|MDA|FAD|FSB|FMU|FDV|AND|OR|XOR|UJP|AZJ,GR|AZJ,GE|AZJ,LS|AZJ,LE|AZJ,EQ|AZJ,NE|SRJ)((,I)?\\s+[0-9]+|\\s+[0-9]+\\s*,\\s*[0-9]+)))\\s*(\\{([^\\}])*\\}\\s*)*$");
	}

	RawOperation* convertLine(QString line)
	{
        RawOperation *res = new RawOperation;

        if (this->_validateLine(line))
        {
            QRegExp r("\\s*([0-9]+)\\s*:\\s*([a-zA-Z]{3,6})(,I)?(\\s*([0-9]+\\.?[0-9]*)\\s*(,\\s*([0-9]+))?)?\\s*((\\{([^\\}])*\\}\\s*)*)");
            int pos = r.indexIn(line);

            res->LineNumber = r.cap(1).toInt();
            res->Operator   = r.cap(2);
            res->indirect   = (r.cap(3).toStdString() == ",I" ? true : false);
            res->Param1     = r.cap(5);
            res->Param2     = r.cap(7);
            res->Comment    = r.cap(8);

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

    if (x = p.convertLine(argv[1]))
    {
        x->show();
	}
}
