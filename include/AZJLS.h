#ifndef AZJLS_H_
#define AZJLS_H_

#include "CompareOperation.h"

//! AZJ,LS b: if AC < 0 then goto b
/*!
 * Trage die Programmadresse b in den BZ ein, falls der Inhalt des AC,
 * interpretiert als Festpunktzahl, kleiner als 0 ist. Sonst erhöhe den Inhalt
 * des BZ um 1.
 */
class AZJLS : public CompareOperation
{
public:
    AZJLS(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJLS_H_*/
