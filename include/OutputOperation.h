#ifndef OUTPUTOPERATION_H_
#define OUTPUTOPERATION_H_

#include "NullaryOperation.h"

//! abstrakte Klasse für Ausgabeoperationen
/*!
 * diese Klasse enthält Methoden, die von Ausgabeoperationen verwendet werden.
 */
class OutputOperation : public NullaryOperation
{
public:
    OutputOperation(RawOperation*);
};

#endif /*OUTPUTOPERATION_H_*/
