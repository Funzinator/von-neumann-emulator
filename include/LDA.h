#ifndef LDA_H_
#define LDA_H_

#include "IndirectOperation.h"

class LDA : public IndirectOperation
{
public:
    LDA(RawOperation*);

    void run(Configuration*);
};

#endif /*LDA_H_*/
