#ifndef FAD_H_
#define FAD_H_

#include "FloatOperation.h"

//! FAD b: AC := AC + Inhalt(b)
/*! 
 * Addiere den Inhalt der Zelle mit der Adresse b zum Inhalt des AC und behalte
 * dabei das Ergebnis im AC. Dabei sind die Inhalte als Gleitpunktzahlen zu
 * interpretieren.
 */
class FAD : public FloatOperation
{
public:
    FAD(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*FAD_H_*/
