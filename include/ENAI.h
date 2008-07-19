#ifndef ENAI_H_
#define ENAI_H_

#include "IndexregisterOperation.h"

class ENAI : public IndexregisterOperation
{
public:
    ENAI(RawOperation*);

    void run(Configuration*);
};

#endif /*ENAI_H_*/
