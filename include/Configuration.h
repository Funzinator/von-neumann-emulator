#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <QMap>
#include <QVector>

#include "CommunicationInterface.h"
#include "StorageCell.h"

//! Konfiguration
/*!
 * Kapselung der Konfiguration.
 */
class Configuration
{
private:
    StorageCell *AC; /* Akkumulator       */
    unsigned int PC; /* Befehlszähler     */
    unsigned int SR; /* Subroutine-Zeiger */
    QMap<unsigned int,StorageCell *> Data;
    QVector<StorageCell *> IndexRegister;
    CommunicationInterface *Interface;

public:
    static const unsigned short int IndexRegisterCount = 16;

    Configuration(CommunicationInterface *);
    ~Configuration();

    StorageCell* getAC();
    unsigned int getPC();
    unsigned int getSR();

    StorageCell* getData(unsigned int);
    StorageCell* getIndexRegister(unsigned int);
    QVector<unsigned int> getUsedData();
    CommunicationInterface* getInterface();

    void setPC(unsigned int);
    void setSR(unsigned int);
};

#endif /*CONFIGURATION_H_*/
