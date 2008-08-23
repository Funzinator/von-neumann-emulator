#ifndef AZJGR_H_
#define AZJGR_H_

#include "CompareOperation.h"

//! AZJ,GR b: if AC > 0 then goto b
/*!
 * Trage die Programmadresse b in den BZ ein, falls der Inhalt des AC,
 * interpretiert als Festpunktzahl, größer als 0 ist. Sonst erhöhe den Inhalt
 * des BZ um 1.
 */
class AZJGR : public CompareOperation
{
public:
    AZJGR(RawOperation*);

    void run(Configuration*);
};

#endif /*AZJGR_H_*/
