#ifndef ADI_H_
#define ADI_H_

#include "IndexregisterOperation.h"

//! ADI b: Inhalt(IRb) := Inhalt(IRb) + AC
/*!
 * Lade Indexregister b mit der Summe des Inhalts von Indexregister b und des
 * AC.
 */
class ADI : public IndexregisterOperation
{
public:
    ADI(RawOperation*);

    /*!
     * \sa Operation::run()
     */
    void run(Configuration*);
};

#endif /*ADI_H_*/
