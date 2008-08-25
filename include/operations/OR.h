#ifndef OR_H_
#define OR_H_

#include "LogicOperation.h"

//! OR b: AC := AC OR Inhalt(b)
/*!
 * Führe mit dem Inhalt der Zelle mit der Adresse b und dem Inhalt des AC die
 * bitweise Oder-Operation OR aus und behalte das Resultat im AC.
 */
class OR : public LogicOperation
{
public:
    OR(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*OR_H_*/
