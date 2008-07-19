#ifndef FSB_H_
#define FSB_H_

#include "FloatOperation.h"

class FSB : public FloatOperation
{
public:
    FSB(RawOperation*);

    void run(Configuration*);
};

#endif /*FSB_H_*/
