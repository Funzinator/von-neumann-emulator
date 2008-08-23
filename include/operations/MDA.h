#ifndef MDA_H_
#define MDA_H_

#include "IntegerOperation.h"

//! MDA b: AC := AC MOD Inhalt(b)
/*!
 * Berechne den Rest der beim Befehl DVA b ausgeführten Division, so dass gilt:
 * Divident = ganzzahliger Quotient * Divisor + Rest. Speichere den Rest in
 * Festpunktdarstellung im AC.
 */
class MDA : public IntegerOperation
{
public:
    MDA(RawOperation*);

    void run(Configuration*);
};

#endif /*MDA_H_*/
