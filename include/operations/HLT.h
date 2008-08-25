#ifndef HLT_H_
#define HLT_H_

#include "NullaryOperation.h"

//! HLT: halt
/*!
 * Beendet die Rechnung irregulär und git eine Fehlermeldung aus.
 */
class HLT : public NullaryOperation
{
public:
    HLT(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*HLT_H_*/
