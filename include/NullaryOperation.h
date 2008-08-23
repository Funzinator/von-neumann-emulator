#ifndef NULLARYOPERATION_H_
#define NULLARYOPERATION_H_

#include "Operation.h"

//! abstrakte Klasse für nulläre Operationen
/*!
 * diese Klasse enthält Methoden, die von nullären Operationen verwendet
 * werden.
 */
class NullaryOperation : public Operation
{
public:
    NullaryOperation(RawOperation*);
};

#endif /*NULLARYOPERATION_H_*/
