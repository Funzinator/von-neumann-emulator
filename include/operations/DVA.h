#ifndef DVA_H_
#define DVA_H_

#include "IntegerOperation.h"

//! DVA b: AC := AC DIV Inhalt(b)
/*!
 * Dividiere den Inhalt des AC durch den Inhalt der Zelle mit der Adresse b und
 * behalte dabei das Ergebnis im AC. Dabei wird zuerst der Quotient der Inhalte
 * berechnet, und dann werden die Nachkommastellen abgeschnitten. Diese Zahl
 * wird als Ergebnis im AC gespeichert.
 */
class DVA : public IntegerOperation
{
public:
    DVA(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*DVA_H_*/
