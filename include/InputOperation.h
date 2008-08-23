#ifndef INPUTOPERATION_H_
#define INPUTOPERATION_H_

#include "NullaryOperation.h"

//! abstrakte Klasse für Eingabeoperationen
/*!
 * diese Klasse enthält Methoden, die von Eingabeoperationen verwendet werden.
 */
class InputOperation : public NullaryOperation
{
public:
    InputOperation(RawOperation*);
};

#endif /*INPUTOPERATION_H_*/
