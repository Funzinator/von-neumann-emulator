#ifndef FNG_H_
#define FNG_H_

#include "NegateOperation.h"

//! FNG: AC := -AC
/*! 
 * Multipliziere den Inhalt des AC mit -1.
 */
class FNG : public NegateOperation
{
public:
    FNG(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*FNG_H_*/
