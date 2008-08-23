#ifndef UJP_H_
#define UJP_H_

#include "ControlOperation.h"

//! UJP b: goto b
/*!
 * Trage die Programmadresse b in den BZ ein.
 */
class UJP : public ControlOperation
{
public:
    UJP(RawOperation*);

    void run(Configuration*);
};

#endif /*UJP_H_*/
