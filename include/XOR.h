#ifndef XOR_H_
#define XOR_H_

#include "RawOperation.h"
#include "LogicOperation.h"

class XOR : public LogicOperation
{
public:
    XOR(RawOperation*);

    void run(Configuration*);
};

#endif /*XOR_H_*/
