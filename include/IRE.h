#ifndef IRE_H_
#define IRE_H_

#include "ConvertOperation.h"

//! IRE: Festpunktzahl in Gleitpunktzahl umwandeln
/*!
 * Der Inhalt des AC wird als Festpunktzahl interpretiert und dann in
 * Gleitpunktdarstellung gebracht.
 */
class IRE : public ConvertOperation
{
public:
    IRE(RawOperation*);

    void run(Configuration*);
};

#endif /*IRE_H_*/
