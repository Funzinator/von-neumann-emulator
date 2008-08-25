#ifndef INB_H_
#define INB_H_

#include "InputOperation.h"

//! INB: Bitfolge einlesen
/*!
 * Lies vom Eingabemedium eine Bitfolge ein, bestimme eine und speichere diese
 * im AC ab. Der Inhalt des Eingabemediums wird dabei um das eingelesene Datum
 * gekürzt. Falls das Eingabemedium leer oder das erste Datum keine Bitfolge
 * war, bricht die Rechnung mit einer Fehlermeldung ab.
 */
class INB : public InputOperation
{
public:
    INB(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*INB_H_*/
