#ifndef CONTROLOPERATION_H_
#define CONTROLOPERATION_H_

#include "IndirectOperation.h"

//! abstrakte Klasse für Kontrolloperationen
/*!
 * diese Klasse enthält Methoden, die von Kontrolloperationen verwendet werden.
 */
class ControlOperation : public IndirectOperation
{
public:
    ControlOperation(RawOperation*);
};

#endif /*CONTROLOPERATION_H_*/
