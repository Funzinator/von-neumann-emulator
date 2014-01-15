#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <QMap>
#include <QVector>
#include <QStack>

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
    QStack<unsigned int> SRStack; /* Subroutine-Stack */
    QMap<unsigned int,StorageCell *> Data;
    QVector<StorageCell *> IndexRegister;
    CommunicationInterface *Interface;

public:
    static const unsigned short int IndexRegisterCount = 16;

    Configuration(CommunicationInterface *);
    ~Configuration();

    StorageCell* getAC();
    unsigned int getPC();
    unsigned int popSR();
    bool isEmptySR();

    StorageCell* getData(unsigned int);
    StorageCell* getIndexRegister(unsigned int);
    QVector<unsigned int> getUsedData();
    QVector<unsigned int> getSRStackContent();
    CommunicationInterface* getInterface();

    void setPC(unsigned int);
    void pushSR(unsigned int);
};

#endif /*CONFIGURATION_H_*/
