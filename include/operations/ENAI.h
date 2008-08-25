#ifndef ENAI_H_
#define ENAI_H_

#include "IndexregisterOperation.h"

//! ENAI b: AC := Inhalt(IRb)
/*!
 * Lade AC mit dem Inhalt von Indexregisters b.
 */
class ENAI : public IndexregisterOperation
{
public:
    ENAI(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*ENAI_H_*/
