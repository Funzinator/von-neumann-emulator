#ifndef RIN_H_
#define RIN_H_

#include <cmath>

#include "ConvertOperation.h"

//! RIN: Gleitpunktzahl in Festpunktzahl umwandeln
/*!
 * Der Inhalt des AC wird als Gleitpunktzahl interpretiert und dann in
 * Festpunktdarstellung gebracht. Falls der Inhalt des AC interpretiert als
 * Gleitpunktzahl keine darstellbare ganze Zahl ergibt, so stoppt die Rechnung
 * mit einer Fehlermeldung.
 */
class RIN : public ConvertOperation
{
public:
    RIN(RawOperation*);

    void run(Configuration*);
};

#endif /*RIN_H_*/
