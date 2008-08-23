#ifndef CONVERTOPERATION_H_
#define CONVERTOPERATION_H_

#include "NullaryOperation.h"

//! abstrakte Klasse für Konvertierungsoperationen
/*!
 * diese Klasse enthält Methoden, die von Konvertierungsoperationen verwendet
 * werden.
 */
class ConvertOperation : public NullaryOperation
{
public:
    ConvertOperation(RawOperation*);
};

#endif /*CONVERTOPERATION_H_*/
