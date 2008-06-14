#ifndef INI_H_
#define INI_H_

#include "RawOperation.h"
#include "InputOperation.h"

class INI : public InputOperation
{
public:
    INI(RawOperation*);

    void run(Configuration*);
};

#endif /*INI_H_*/
