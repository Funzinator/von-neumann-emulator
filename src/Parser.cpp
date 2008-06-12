#include "Parser.h"

bool Parser::validateLine(QString line)
{
    return this->ParseRegExp->exactMatch(line);
}

Parser::Parser()
{
    this->ParseRegExp = new QRegExp(PARSE_REGEXP);
    this->SplitRegExp = new QRegExp(SPLIT_REGEXP);
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
        res->Operator = this->SplitRegExp->cap(2);
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
                op[rawOp->LineNumber] = new ENAI(rawOp);
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
            else if (rawOp->Operator == "UJP")
            {
                op[rawOp->LineNumber] = new UJP(rawOp);
            }
            else if (rawOp->Operator == "ENAR")
            {
                op[rawOp->LineNumber] = new ENAR(rawOp);
            }
            else
            {
                op[rawOp->LineNumber] = new NOP(rawOp);
                /* FIXME - wenn alle Befehle drin sind, kann das weg */
                std::cout << "unbekannter Befehl '" << rawOp->Operator.toStdString() << "'" << std::endl;
            }
        }

        delete rawOp;
        rawOp = 0;
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
