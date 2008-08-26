#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include "Operation.h"

//! Interpreter
/*!
 * Ruft die jeweils aktuelle Operation auf und ändert dadurch die
 * Konfiguration.
 */
class Interpreter
{
private:
    Configuration *config;
    QMap<unsigned int, Operation *> ops;
    
public:
    /*!
     * \param ops    QMap mit Operationen
     * \param config Konfiguration
     */
    Interpreter(QMap<unsigned int, Operation *>, Configuration*);

    //! führt den nächsten Befehl aus oder terminiert mit einer Fehlermeldung
    void next();

    //! liefert einen Zeiger auf die verwendete Konfiguration
    /*!
     * \return Konfiguration
     */
    Configuration *getConfiguration();

    //! liefert den Namen der als nächstes auszuführenden Operation
    /*!
     * \sa Operation::getOperationName
     * \param full vollständige Angabe der Parameter
     */
    QString getNextOperation(bool);
};

#endif /*INTERPRETER_H_*/
