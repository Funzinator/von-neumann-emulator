#ifndef LOGICOPERATION_H_
#define LOGICOPERATION_H_

#include "IndirectOperation.h"

//! abstrakte Klasse für Logikoperationen
/*!
 * diese Klasse enthält Methoden, die von Logikoperationen verwendet werden.
 */
class LogicOperation : public IndirectOperation
{
public:
    LogicOperation(RawOperation*);
};

#endif /*LOGICOPERATION_H_*/
