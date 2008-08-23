#ifndef UNARYOPERATION_H_
#define UNARYOPERATION_H_

#include "Operation.h"

//! abstrakte Klasse für unäre Operationen
/*!
 * diese Klasse enthält Methoden, die von unären Operationen verwendet werden.
 */
class UnaryOperation : public Operation
{
public:
    UnaryOperation(RawOperation*);
};

#endif /*UNARYOPERATION_H_*/
