#ifndef ENIA_H_
#define ENIA_H_

#include "IndexregisterOperation.h"

//! ENIA b: Inhalt(IRb) := AC
/*!
 * Lade Indexregister b mit dem Inhalt des AC.
 */
class ENIA : public IndexregisterOperation
{
public:
    ENIA(RawOperation*);

    void run(Configuration*);
};

#endif /*ENIA_H_*/
