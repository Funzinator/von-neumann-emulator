#ifndef AND_H_
#define AND_H_

#include "LogicOperation.h"

//! AND b: AC := AC AND Inhalt(b)
/*!
 * Führe mit dem Inhalt der Zelle mit der Adresse b und dem Inhalt des AC die
 * bitweise Und-Operation AND aus und behalte das Resultat im AC.
 */
class AND : public LogicOperation
{
public:
    AND(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*AND_H_*/
