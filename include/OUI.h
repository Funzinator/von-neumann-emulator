#ifndef OUI_H_
#define OUI_H_

#include "OutputOperation.h"

class OUI : public OutputOperation
{
public:
    OUI(RawOperation*);

    void run(Configuration*);
};

#endif /*OUI_H_*/
