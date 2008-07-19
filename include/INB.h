#ifndef INB_H_
#define INB_H_

#include "InputOperation.h"

class INB : public InputOperation
{
public:
    INB(RawOperation*);

    void run(Configuration*);
};

#endif /*INB_H_*/
