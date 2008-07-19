#ifndef OUR_H_
#define OUR_H_

#include "OutputOperation.h"

class OUR : public OutputOperation
{
public:
    OUR(RawOperation*);

    void run(Configuration*);
};

#endif /*OUR_H_*/
