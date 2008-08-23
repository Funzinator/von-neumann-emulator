#ifndef MUA_H_
#define MUA_H_

#include "IntegerOperation.h"

//! MUA b: AC := AC * Inhalt(b)
/*!
 * Multipliziere den Inhalt der Zelle mit der Adresse b mit dem Inhalt des AC
 * und behalte dabei das Ergebnis im AC. Dabei sind die Inhalte als
 * Festpunktzahlen zu interpretieren.
 */
class MUA : public IntegerOperation
{
public:
    MUA(RawOperation*);

    void run(Configuration*);
};

#endif /*MUA_H_*/
