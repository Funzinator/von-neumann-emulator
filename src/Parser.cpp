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
        res->indirect = (this->SplitRegExp->cap(3).toStdString() == ",I" ? true : false);

        return res;
    }
    else
    {
        return 0;
    }
}
