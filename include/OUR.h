#ifndef OUR_H_
#define OUR_H_

#include "OutputOperation.h"

//! OUR: Gleitpunktzahl ausgeben
/*!
 * Verlängert den Inhalt des Ausgabemediums um den Inhalt im AC. Dabei wird der
 * Inhalt des AC als Gleitpunktzahl interpretiert und als Dezimalbruch mit
 * eventuellem Vorzeichen ausgegeben.
 */
class OUR : public OutputOperation
{
public:
    OUR(RawOperation*);

    void run(Configuration*);
};

#endif /*OUR_H_*/
