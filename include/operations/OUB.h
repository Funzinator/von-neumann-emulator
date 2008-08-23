#ifndef OUB_H_
#define OUB_H_

#include "OutputOperation.h"

//! OUB: Bitfolge ausgeben
/*!
 * Verlängert den Inhalt des Ausgabemediums um den Inhalt im AC. Dabei wird der
 * Inhalt des AC als Bitfolge interpretiert und als Bitfolge ausgegeben.
 */
class OUB : public OutputOperation
{
public:
    OUB(RawOperation*);

    void run(Configuration*);
};

#endif /*OUB_H_*/
