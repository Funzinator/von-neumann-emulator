#ifndef AZJNE_H_
#define AZJNE_H_

#include "CompareOperation.h"

//! AZJ,NE b: if AC != 0 then goto b
/*!
 * Trage die Programmadresse b in den BZ ein, falls der Inhalt des AC,
 * interpretiert als Festpunktzahl, ungleich 0 ist. Sonst erhöhe den Inhalt des
 * BZ um 1.
 */
class AZJNE : public CompareOperation
{
public:
    AZJNE(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJNE_H_*/
