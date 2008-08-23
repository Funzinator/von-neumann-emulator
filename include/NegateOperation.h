#ifndef NEGATEOPERATION_H_
#define NEGATEOPERATION_H_

#include "NullaryOperation.h"

//! abstrakte Klasse für Negierungsoperationen
/*!
 * diese Klasse enthält Methoden, die von Negierungsoperationen verwendet
 * werden.
 */
class NegateOperation : public NullaryOperation
{
public:
    NegateOperation(RawOperation*);
};

#endif /*NEGATEOPERATION_H_*/
