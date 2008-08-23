#ifndef COMPAREOPERATION_H_
#define COMPAREOPERATION_H_

#include "ControlOperation.h"

//! abstrakte Klasse für Vergleichsoperationen
/*!
 * diese Klasse enthält Methoden, die von Vergleichsoperationen verwendet
 * werden.
 */
class CompareOperation : public ControlOperation
{
public:
    CompareOperation(RawOperation*);
};

#endif /*COMPAREOPERATION_H_*/
