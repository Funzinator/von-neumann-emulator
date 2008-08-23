#ifndef INR_H_
#define INR_H_

#include "InputOperation.h"

//! INR: Gleitpunktzahl einlesen
/*!
 * Lies vom Eingabemedium einen Dezimalbruch mit Vorzeichen ein, bestimme eine
 * nächstgelegene darstellbare Zahl und speichere diese in
 * Gleitpunktdarstellung im AC ab. Der Inhalt des Eingabemediums wird dabei um
 * das eingelesene Datum gekürzt. Falls das Eingabemedium leer oder das erste
 * Datum kein Dezimalbruch war, bricht die Rechnung mit einer Fehlermeldung ab.
 */
class INR : public InputOperation
{
public:
    INR(RawOperation*);

    void run(Configuration*);
};

#endif /*INR_H_*/
