#ifndef FLOATOPERATION_H_
#define FLOATOPERATION_H_

#include "IndirectOperation.h"

//! abstrakte Klasse für Gleitpunktzahloperationen
/*!
 * diese Klasse enthält Methoden, die von Gleitpunktzahloperationen verwendet
 * werden.
 */
class FloatOperation : public IndirectOperation
{
public:
    FloatOperation(RawOperation*);
};

#endif /*FLOATOPERATION_H_*/
