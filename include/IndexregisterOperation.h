#ifndef INDEXREGISTEROPERATION_H_
#define INDEXREGISTEROPERATION_H_

#include "UnaryOperation.h"

//! abstrakte Klasse für Indexregisteroerationen
/*!
 * diese Klasse enthält Methoden, die von Indexregisteroperationen verwendet werden.
 */
class IndexregisterOperation : public UnaryOperation
{
public:
    IndexregisterOperation(RawOperation*);

protected:
    //! OP,I b: OP (Inhalt(b))
    /*! 
     * Bei der indirekten Adressierung wird als Adresse, der in Adresse b
     * gespeicherte Wert verwendet.
     * \param c Konfiguration
     */
    StorageCell* IndirectToDirect(Configuration*);
};

#endif /*INDEXREGISTEROPERATION_H_*/
