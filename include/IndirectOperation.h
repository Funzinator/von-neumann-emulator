#ifndef INDIRECTOPERATION_H_
#define INDIRECTOPERATION_H_

#include "IndexregisterOperation.h"

//! abstrakte Klasse für indirekte Operationen
/*!
 * diese Klasse enthält Methoden, die von indirekten Operationen verwendet
 * werden.
 */
class IndirectOperation : public IndexregisterOperation
{
public:
    IndirectOperation(RawOperation*);

protected:
    StorageCell* BinaryToUnary(Configuration*);
    StorageCell* setP1(Configuration*);
};

#endif /*INDIRECTOPERATION_H_*/
