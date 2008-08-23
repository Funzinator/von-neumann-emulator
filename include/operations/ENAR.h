#ifndef ENAR_H_
#define ENAR_H_

#include "UnaryOperation.h"

//! ENAR b: AC := b
/*!
 * Lade AC mit Gleitpunktzahl b.
 */
class ENAR : public UnaryOperation
{
public:
    ENAR(RawOperation*);

    void run(Configuration*);
};

#endif /*ENAR_H_*/
