#ifndef OPERATION_H_
#define OPERATION_H_

#include "RawOperation.h"
#include "Configuration.h"

//! abstrakte Operationsklasse
/*!
 * abstrakte Klasse, die die Grundfunktionalität einer Operation zur Verfügung
 * stellt.
 */
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
