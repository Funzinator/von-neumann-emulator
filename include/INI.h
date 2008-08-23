#ifndef INI_H_
#define INI_H_

#include "InputOperation.h"

//! INI: Festpunktzahl einlesen
/*!
 * Lies vom Eingabemedium eine Festpunktzahl mit Vorzeichen ein, bestimme eine
 * nächstgelegene darstellbare Zahl und speichere diese in Festpunktdarstellung
 * im AC ab. Der Inhalt des Eingabemediums wird dabei um das eingelesene Datum
 * gekürzt. Falls das Eingabemedium leer oder das erste Datum keine
 * Festpunktzahl war, bricht die Rechnung mit einer Fehlermeldung ab.
 */
class INI : public InputOperation
{
public:
    INI(RawOperation*);

    void run(Configuration*);
};

#endif /*INI_H_*/
