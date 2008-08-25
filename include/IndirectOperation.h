#ifndef INDIRECTOPERATION_H_
#define INDIRECTOPERATION_H_

#include "IndexregisterOperation.h"

//! abstrakte Klasse für indirekte Operationen
/*!
 * diese Klasse enthält Methoden, die von indirekten Operationen verwendet
 * werden.
 */
class IndirectOperation : public IndexregisterOperation
{
public:
    IndirectOperation(RawOperation*);

protected:
    //! OP a,b: OP (a + Inhalt(IRb))
    /*! 
     * Bei der Indexregistermodifikation wird die Adresse des Operanden aus der
     * Summe der im Operandenteil angegebenen Adresse und dem Inhalt des
     * Indexregisters gebildet. D.h. zur angegebenen Adresse und dem Inhalt des
     * angegebenen Indexregisters aufaddiert und das Ergebnis ist diejenige
     * Adresse, auf die sich der Befehl bezieht.
     * \param c Konfiguration
     */
    StorageCell* BinaryToUnary(Configuration*);

    //! initialisiert den ersten Parameter abhängig vom Modus
    /*!
     * \param c Konfiguration
     * \sa IndirectOperation::BinaryToUnary
     * \sa IndexregisterOperation::IndirectToDirect
     */
    StorageCell* setP1(Configuration*);
};

#endif /*INDIRECTOPERATION_H_*/
