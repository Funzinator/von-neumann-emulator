#ifndef OUI_H_
#define OUI_H_

#include "OutputOperation.h"

//! OUI: Festpunktzahl ausgeben
/*!
 * Verlängert den Inhalt des Ausgabemediums um den Inhalt im AC. Dabei wird der
 * Inhalt des AC als Festpunktzahl interpretiert und als Festpunktzahl mit
 * eventuellem Vorzeichen ausgegeben.
 */
class OUI : public OutputOperation
{
public:
    OUI(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*OUI_H_*/
