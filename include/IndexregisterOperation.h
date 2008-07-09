#ifndef INDEXREGISTEROPERATION_H_
#define INDEXREGISTEROPERATION_H_

#include "UnaryOperation.h"

class IndexregisterOperation : public UnaryOperation
{
public:
    IndexregisterOperation(RawOperation*);

protected:
    StorageCell* IndirectToDirect(Configuration*);
};

#endif /*INDEXREGISTEROPERATION_H_*/
