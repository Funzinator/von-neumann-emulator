#ifndef ENI_H_
#define ENI_H_

#include "IndexregisterOperation.h"

//! ENI a,b: Inhalt(IRa) := b
/*!
 * Lade das Indexregister mit der Adresse a AC mit Festpunktzahl b.
 */
class ENI : public IndexregisterOperation
{
public:
    ENI(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*ENI_H_*/
