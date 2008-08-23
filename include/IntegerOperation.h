#ifndef INTEGEROPERATION_H_
#define INTEGEROPERATION_H_

#include "IndirectOperation.h"

//! abstrakte Klasse für Festpunktzahloperationen
/*!
 * diese Klasse enthält Methoden, die von Festpunktzahloperationen verwendet
 * werden.
 */
class IntegerOperation : public IndirectOperation
{
public:
    IntegerOperation(RawOperation*);
};

#endif /*INTEGEROPERATION_H_*/
