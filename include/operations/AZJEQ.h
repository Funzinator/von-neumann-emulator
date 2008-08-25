#ifndef AZJEQ_H_
#define AZJEQ_H_

#include "CompareOperation.h"

//! AZJ,EQ b: if AC = 0 then goto b
/*!
 * Trage die Programmadresse b in den BZ ein, falls der Inhalt des AC,
 * interpretiert als Festpunktzahl, gleich 0 ist. Sonst erhöhe den Inhalt des
 * BZ um 1.
 */
class AZJEQ : public CompareOperation
{
public:
    AZJEQ(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*AZJEQ_H_*/
