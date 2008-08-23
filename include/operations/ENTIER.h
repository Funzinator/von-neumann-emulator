#ifndef ENTIER_H_
#define ENTIER_H_

#include <cmath>

#include "ConvertOperation.h"

//! ENTIER: Ganzzahlfunktion
/*!
 * Der Inhalt des AC wird als Gleitpunktzahl interpretiert. Dann wird die
 * größte ganze Zahl, die kleiner oder gleich der Zahl ist, bestimmt und in
 * Festpunktdarstellung im AC gespeichert.
 */
class ENTIER : public ConvertOperation
{
public:
    ENTIER(RawOperation*);

    void run(Configuration*);
};

#endif /*ENTIER_H_*/
