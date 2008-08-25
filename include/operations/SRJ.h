#ifndef SRJ_H_
#define SRJ_H_

#include "IndirectOperation.h"

//! SRJ b: Springe zu Unterprogramm in Zeile b
/*!
 * Trage die Programmadresse b in den BZ ein. Trage die um 1 erhöhte Adresse,
 * an der der Befehl SRJ steht, in SR ein.
 */
class SRJ : public IndirectOperation
{
public:
    SRJ(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*SRJ_H_*/
