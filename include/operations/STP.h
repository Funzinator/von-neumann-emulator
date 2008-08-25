#ifndef STP_H_
#define STP_H_

#include "NullaryOperation.h"

//! STP: Stop
/*!
 * Beendet die Rechnung regulär.
 */
class STP : public NullaryOperation
{
public:
    STP(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*STP_H_*/
