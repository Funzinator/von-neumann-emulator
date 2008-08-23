#ifndef ADA_H_
#define ADA_H_

#include "IntegerOperation.h"

//! ADA b: AC := AC + Inhalt(b)
/*!
 * Addiere den Inhalt der Zelle mit der Adresse b zum Inhalt des AC und behalte
 * dabei das Ergebnis im AC. Dabei sind die Inhalte als Festpunktzahlen zu
 * interpretieren. 
 */
class ADA : public IntegerOperation
{
public:
    ADA(RawOperation*);

    void run(Configuration*);
};

#endif /*ADA_H_*/
