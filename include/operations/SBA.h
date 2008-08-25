#ifndef SBA_H_
#define SBA_H_

#include "IntegerOperation.h"

//! SBA b: AC := AC - Inhalt(b)
/*!
 * Subtrahiere den Inhalt der Zelle mit der Adresse b vom Inhalt des AC und
 * behalte dabei das Ergebnis im AC. Dabei sind die Inhalte als Festpunktzahlen
 * zu interpretieren.
 */
class SBA : public IntegerOperation
{
public:
    SBA(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*SBA_H_*/
