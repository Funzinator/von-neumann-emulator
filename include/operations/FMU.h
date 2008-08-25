#ifndef FMU_H_
#define FMU_H_

#include "FloatOperation.h"

//! FMU b: AC := AC * Inhalt(b)
/*! 
 * Multipliziere den Inhalt der Zelle mit der Adresse b mit dem Inhalt des AC
 * und behalte dabei das Ergebnis im AC. Dabei sind die Inhalte als
 * Gleitpunktzahlen zu interpretieren.
 */
class FMU : public FloatOperation
{
public:
    FMU(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*FMU_H_*/
