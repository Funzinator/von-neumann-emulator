#include "Parser.h"

bool Parser::validateLine(QString line)
{
    return this->ParseRegExp->exactMatch(line);
}

Parser::Parser()
{
    this->ParseRegExp = new QRegExp(PARSE_REGEXP, Qt::CaseInsensitive);
    this->SplitRegExp = new QRegExp(SPLIT_REGEXP, Qt::CaseInsensitive);
}

Parser::~Parser()
{
    delete this->ParseRegExp;
    delete this->SplitRegExp;
}

RawOperation* Parser::convertLine(QString line)
{
    RawOperation *res = new RawOperation;

    if (this->validateLine(line))
    {
        this->SplitRegExp->indexIn(line);

        res->LineNumber = this->SplitRegExp->cap(1).toInt();
        res->Operator = this->SplitRegExp->cap(2).toUpper();
        res->Param1 = this->SplitRegExp->cap(5);
        res->Param2 = this->SplitRegExp->cap(7);
        res->Comment = this->SplitRegExp->cap(8);
        res->indirect = (this->SplitRegExp->cap(3).toStdString() == ",I");

        return res;
    }
    else
    {
        return 0;
    }
}

QMap<unsigned int,Operation *> Parser::Parse(QVector<QString> input)
{
    QMap<unsigned int,Operation *> op;

    for (int i = 0; i < input.count(); i++)
    {
        RawOperation *rawOp = this->convertLine(input[i]);

        if (rawOp != 0)
        {
            if (rawOp->Operator == "ADA")
            {
                op[rawOp->LineNumber] = new ADA(rawOp);
            }
            else if (rawOp->Operator == "ADI")
            {
                op[rawOp->LineNumber] = new ADI(rawOp);
            }
            else if (rawOp->Operator == "AND")
            {
                op[rawOp->LineNumber] = new AND(rawOp);
            }
            else if (rawOp->Operator == "AZJ,EQ")
            {
                op[rawOp->LineNumber] = new AZJEQ(rawOp);
            }
            else if (rawOp->Operator == "AZJ,GE")
            {
                op[rawOp->LineNumber] = new AZJGE(rawOp);
            }
            else if (rawOp->Operator == "AZJ,GR")
            {
                op[rawOp->LineNumber] = new AZJGR(rawOp);
            }
            else if (rawOp->Operator == "AZJ,LE")
            {
                op[rawOp->LineNumber] = new AZJLE(rawOp);
            }
            else if (rawOp->Operator == "AZJ,LS")
            {
                op[rawOp->LineNumber] = new AZJLS(rawOp);
            }
            else if (rawOp->Operator == "AZJ,NE")
            {
                op[rawOp->LineNumber] = new AZJNE(rawOp);
            }
            else if (rawOp->Operator == "DVA")
            {
                op[rawOp->LineNumber] = new DVA(rawOp);
            }
            else if (rawOp->Operator == "ENA")
            {
                op[rawOp->LineNumber] = new ENA(rawOp);
            }
            else if (rawOp->Operator == "ENAI")
            {
                op[rawOp->LineNumber] = new ENAI(rawOp);
            }
            else if (rawOp->Operator == "ENAR")
            {
                op[rawOp->LineNumber] = new ENAR(rawOp);
            }
            else if (rawOp->Operator == "ENI")
            {
                op[rawOp->LineNumber] = new ENI(rawOp);
            }
            else if (rawOp->Operator == "ENIA")
            {
                op[rawOp->LineNumber] = new ENIA(rawOp);
            }
            else if (rawOp->Operator == "ENTIER")
            {
                op[rawOp->LineNumber] = new ENTIER(rawOp);
            }
            else if (rawOp->Operator == "FAD")
            {
                op[rawOp->LineNumber] = new FAD(rawOp);
            }
            else if (rawOp->Operator == "FDV")
            {
                op[rawOp->LineNumber] = new FDV(rawOp);
            }
            else if (rawOp->Operator == "FMU")
            {
                op[rawOp->LineNumber] = new FMU(rawOp);
            }
            else if (rawOp->Operator == "FNG")
            {
                op[rawOp->LineNumber] = new FNG(rawOp);
            }
            else if (rawOp->Operator == "FSB")
            {
                op[rawOp->LineNumber] = new FSB(rawOp);
            }
            else if (rawOp->Operator == "HLT")
            {
                op[rawOp->LineNumber] = new HLT(rawOp);
            }
            else if (rawOp->Operator == "INB")
            {
                op[rawOp->LineNumber] = new INB(rawOp);
            }
            else if (rawOp->Operator == "INI")
            {
                op[rawOp->LineNumber] = new INI(rawOp);
            }
            else if (rawOp->Operator == "INR")
            {
                op[rawOp->LineNumber] = new INR(rawOp);
            }
            else if (rawOp->Operator == "IRE")
            {
                op[rawOp->LineNumber] = new IRE(rawOp);
            }
            else if (rawOp->Operator == "LDA")
            {
                op[rawOp->LineNumber] = new LDA(rawOp);
            }
            else if (rawOp->Operator == "MDA")
            {
                op[rawOp->LineNumber] = new MDA(rawOp);
            }
            else if (rawOp->Operator == "MUA")
            {
                op[rawOp->LineNumber] = new MUA(rawOp);
            }
            else if (rawOp->Operator == "NGA")
            {
                op[rawOp->LineNumber] = new NGA(rawOp);
            }
            else if (rawOp->Operator == "NOP")
            {
                op[rawOp->LineNumber] = new NOP(rawOp);
            }
            else if (rawOp->Operator == "NOT")
            {
                op[rawOp->LineNumber] = new NOT(rawOp);
            }
            else if (rawOp->Operator == "OR")
            {
                op[rawOp->LineNumber] = new OR(rawOp);
            }
            else if (rawOp->Operator == "OUB")
            {
                op[rawOp->LineNumber] = new OUB(rawOp);
            }
            else if (rawOp->Operator == "OUI")
            {
                op[rawOp->LineNumber] = new OUI(rawOp);
            }
            else if (rawOp->Operator == "OUR")
            {
                op[rawOp->LineNumber] = new OUR(rawOp);
            }
            else if (rawOp->Operator == "PRIM")
            {
                op[rawOp->LineNumber] = new PRIM(rawOp);
            }
            else if (rawOp->Operator == "RIN")
            {
                op[rawOp->LineNumber] = new RIN(rawOp);
            }
            else if (rawOp->Operator == "SBA")
            {
                op[rawOp->LineNumber] = new SBA(rawOp);
            }
            else if (rawOp->Operator == "SBI")
            {
                op[rawOp->LineNumber] = new SBI(rawOp);
            }
            else if (rawOp->Operator == "SRJ")
            {
                op[rawOp->LineNumber] = new SRJ(rawOp);
            }
            else if (rawOp->Operator == "SRR")
            {
                op[rawOp->LineNumber] = new SRR(rawOp);
            }
            else if (rawOp->Operator == "STA")
            {
                op[rawOp->LineNumber] = new STA(rawOp);
            }
            else if (rawOp->Operator == "STP")
            {
                op[rawOp->LineNumber] = new STP(rawOp);
            }
            else if (rawOp->Operator == "UJP")
            {
                op[rawOp->LineNumber] = new UJP(rawOp);
            }
            else if (rawOp->Operator == "XOR")
            {
                op[rawOp->LineNumber] = new XOR(rawOp);
            }
        }
        delete rawOp;
    }
    return op;
}

QMap<unsigned int,Operation *> Parser::Parse(QFile *file)
{
    QVector<QString> input;

    file->open(QIODevice::ReadOnly | QIODevice::Text);
    while (!file->atEnd())
    {
        input.append(file->readLine());
    }

    return this->Parse(input);
}

QMap<unsigned int,Operation *> Parser::Parse(QString plainText)
{
    QVector<QString> input;
    QString tmp(plainText);
    QStringList list = tmp.split("\n", QString::SkipEmptyParts);

    for (int i = 0; i < list.size(); i++)
    {
        input.append(list.at(i).toUtf8().constData());
    }

    return this->Parse(input);
}
