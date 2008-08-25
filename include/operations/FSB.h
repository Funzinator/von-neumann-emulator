#ifndef FSB_H_
#define FSB_H_

#include "FloatOperation.h"

//! FSB b: AC := AC - Inhalt(b)
/*! 
 * Subtrahiere den Inhalt der Zelle mit der Adresse b vom Inhalt des AC und
 * behalte dabei das Ergebnis im AC. Dabei sind die Inhalte als
 * Gleitpunktzahlen zu interpretieren.
 */
class FSB : public FloatOperation
{
public:
    FSB(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*FSB_H_*/
