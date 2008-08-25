#ifndef SRR_H_
#define SRR_H_

#include "NullaryOperation.h"

class SRR : public NullaryOperation
{
public:
    SRR(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*SRR_H_*/
