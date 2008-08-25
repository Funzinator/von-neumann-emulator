#ifndef NGA_H_
#define NGA_H_

#include "NegateOperation.h"

//! NGA: AC := -AC
/*! 
 * Multipliziere den Inhalt des AC mit -1.
 */
class NGA : public NegateOperation
{
public:
    NGA(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*NGA_H_*/
