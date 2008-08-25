#ifndef NOT_H_
#define NOT_H_

#include "NegateOperation.h"

//! NOT: AC := NOT AC
/*!
 * Negiere den Inhalt des AC bitweise.
 */
class NOT : public NegateOperation
{
public:
    NOT(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*NOT_H_*/
