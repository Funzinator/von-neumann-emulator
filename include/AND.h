#ifndef AND_H_
#define AND_H_

#include "LogicOperation.h"

class AND : public LogicOperation
{
public:
    AND(RawOperation*);

    void run(Configuration*);
};

#endif /*AND_H_*/
