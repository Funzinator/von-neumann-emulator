#ifndef INDEXREGISTEROPERATION_H_
#define INDEXREGISTEROPERATION_H_

#include "UnaryOperation.h"

class IndexregisterOperation : public UnaryOperation
{
public:
    IndexregisterOperation(RawOperation*);
    StorageCell* BinaryToUnary(Configuration*);
};

#endif /*INDEXREGISTEROPERATION_H_*/
