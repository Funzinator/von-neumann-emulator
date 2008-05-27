#ifndef RAWOPERATION_H_
#define RAWOPERATION_H_

#include <iostream>
#include <QString>

struct RawOperation
{
    unsigned int LineNumber;
    QString Operator;
    QString Param1;
    QString Param2;
    QString Comment;
    bool indirect;
    
    void show();
};
#endif /*RAWOPERATION_H_*/
