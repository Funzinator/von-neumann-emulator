#ifndef STA_H_
#define STA_H_

#include "IndirectOperation.h"

class STA : public IndirectOperation
{
public:
    STA(RawOperation*);

    void run(Configuration*);
};

#endif /*STA_H_*/
