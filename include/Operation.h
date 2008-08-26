#ifndef OPERATION_H_
#define OPERATION_H_

#include "RawOperation.h"
#include "Configuration.h"

//! abstrakte Operationsklasse
/*!
 * abstrakte Klasse, die die Grundfunktionalität einer Operation zur Verfügung
 * stellt.
 */
class Operation
{
protected:
    StorageCell *Param1;
    StorageCell *Param2;
    bool indirect;
    QString Operatorname;
    QString Comment;
    
public:
    Operation(RawOperation*);
    ~Operation();

    //! gibt den Namen der Operation zurück. Wahlweise mit Parametern
    /*!
     * \param full vollständige Angabe der Parameter
     */
    QString getOperationName(bool);

    //! wendet die abgeleitete Operation auf die Konfiguration an
    /*
     * \param c zu verändernde Konfiguration
     */
    virtual void run(Configuration* c) = 0;
};

#endif /*OPERATION_H_*/
