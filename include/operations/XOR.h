#ifndef XOR_H_
#define XOR_H_

#include "LogicOperation.h"

//! XOR b: AC := AC XOR Inhalt(b)
/*!
 * Führe mit dem Inhalt der Zelle mit der Adresse b und dem Inhalt des AC die
 * bitweise ausschließendes-Oder-Operation XOR aus und behalte das Resultat im
 * AC.
 */
class XOR : public LogicOperation
{
public:
    XOR(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*XOR_H_*/
