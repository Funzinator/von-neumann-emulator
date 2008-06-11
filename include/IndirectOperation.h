#ifndef INDIRECTOPERATION_H_
#define INDIRECTOPERATION_H_

#include "IndexregisterOperation.h"

class IndirectOperation : public IndexregisterOperation
{
public:
    IndirectOperation(RawOperation*);
    StorageCell* IndirectToDirect(Configuration*);
};

#endif /*INDIRECTOPERATION_H_*/
