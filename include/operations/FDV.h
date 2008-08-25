#ifndef FDV_H_
#define FDV_H_

#include "FloatOperation.h"

//! FDV b: AC := AC / Inhalt(b)
/*! 
 * Dividiere des AC durch den Inhalt der Zelle mit der Adresse b und behalte
 * dabei das Ergebnis im AC. Dabei sind die Inhalte als Gleitpunktzahlen zu
 * interpretieren.
 */
class FDV : public FloatOperation
{
public:
    FDV(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*FDV_H_*/
