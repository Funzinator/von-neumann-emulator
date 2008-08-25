#ifndef STA_H_
#define STA_H_

#include "IndirectOperation.h"

//! STA b: Inhalt(b) := AC
/*!
 * Speichere den Inhalt des AC in derjenigen Zelle, die durch Adresse b
 * gekennzeichnet ist.
 */
class STA : public IndirectOperation
{
public:
    STA(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*STA_H_*/
