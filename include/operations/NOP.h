#ifndef NOP_H_
#define NOP_H_

#include "NullaryOperation.h"

//! NOP: keine Operation
/*!
 * Es wird wie bei allen Rechenbefehlen der Inhalt des BZ um 1 erhöht.
 * Ansonsten geschieht nichts.
 */
class NOP : public NullaryOperation
{
public:
    NOP(RawOperation*);

    void run(Configuration*);
};

#endif /*NOP_H_*/
