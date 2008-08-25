#ifndef LDA_H_
#define LDA_H_

#include "IndirectOperation.h"

//! LDA b: AC := Inhalt(b)
/*!
 * Lade AC mit dem Inhalt derjenigen Zelle, die durch die Adresse b
 * gekennzeichnet ist.
 */
class LDA : public IndirectOperation
{
public:
    LDA(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*LDA_H_*/
