#ifndef ENTIRE_H_
#define ENTIRE_H_

#include <cmath>

#include "ConvertOperation.h"

//! ENTIRE: Ganzzahlfunktion
/*!
 * Der Inhalt des AC wird als Gleitpunktzahl interpretiert. Dann wird die
 * größte ganze Zahl, die kleiner oder gleich der Zahl ist, bestimmt und in
 * Festpunktdarstellung im AC gespeichert.
 */
class ENTIRE : public ConvertOperation
{
public:
    ENTIRE(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*ENTIRE_H_*/
