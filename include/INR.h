#ifndef INR_H_
#define INR_H_

#include "RawOperation.h"
#include "InputOperation.h"

class INR : public InputOperation
{
public:
    INR(RawOperation*);

    void run(Configuration*);
};

#endif /*INR_H_*/
