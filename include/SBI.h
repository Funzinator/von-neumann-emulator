#ifndef SBI_H_
#define SBI_H_

#include "IndexregisterOperation.h"

//! SBI b: Inhalt(IRb) := Inhalt(IRb) - AC
/*!
 * Lade Indexregister b mit der Differenz des Inhalts von Indexregister b und
 * des AC.
 */
class SBI : public IndexregisterOperation
{
public:
    SBI(RawOperation*);

    void run(Configuration*);
};

#endif /*SBI_H_*/
