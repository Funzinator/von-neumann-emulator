#ifndef PRIM_H_
#define PRIM_H_

#include "NullaryOperation.h"

//! PRIM: Primzahltest
/*!
 * Lade den AC mit 1, wenn der Inhalt des AC, interpretiert als Festpunktzahl,
 * einer Primzahl entspricht. Sonst lade den AC mit 0. 
 */
class PRIM : public NullaryOperation
{
private:
    bool prim(unsigned int);

public:
    PRIM(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*PRIM_H_*/
