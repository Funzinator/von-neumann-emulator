#ifndef ENA_H_
#define ENA_H_

#include "UnaryOperation.h"

//! ENA b: AC := b
/*!
 * Lade AC mit Festpunktzahl b.
 */
class ENA : public UnaryOperation
{
public:
    ENA(RawOperation*);

    void run(Configuration*);
};

#endif /*ENA_H_*/
