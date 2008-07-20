#ifndef OPERATION_H_
#define OPERATION_H_

#include <QString>

#include "StorageCell.h"
#include "RawOperation.h"
#include "Configuration.h"

class Operation
{
protected:
    StorageCell *Param1;
    StorageCell *Param2;
    bool indirect;
    QString Operatorname;
    QString Comment;
    
public:
    Operation(RawOperation*);
    ~Operation();

    QString getOperationName(bool);

    virtual void run(Configuration*) = 0;
};

#endif /*OPERATION_H_*/
