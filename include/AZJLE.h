#ifndef AZJLE_H_
#define AZJLE_H_

#include "CompareOperation.h"

//! AZJ,LE b: if AC <= 0 then goto b
/*!
 * Trage die Programmadresse b in den BZ ein, falls der Inhalt des AC,
 * interpretiert als Festpunktzahl, kleiner oder gleich 0 ist. Sonst erhöhe den
 * Inhalt des BZ um 1.
 */
class AZJLE : public CompareOperation
{
public:
    AZJLE(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJLE_H_*/
