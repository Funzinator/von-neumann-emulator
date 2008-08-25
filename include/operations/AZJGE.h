#ifndef AZJGE_H_
#define AZJGE_H_

#include "CompareOperation.h"

//! AZJ,GE b: if AC >= 0 then goto b
/*!
 * Trage die Programmadresse b in den BZ ein, falls der Inhalt des AC,
 * interpretiert als Festpunktzahl, größer oder gleich 0 ist. Sonst erhöhe den
 * Inhalt des BZ um 1.
 */
class AZJGE : public CompareOperation
{
public:
    AZJGE(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*AZJGE_H_*/
