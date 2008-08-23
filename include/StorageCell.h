#ifndef STORAGECELL_H_
#define STORAGECELL_H_

#include <QString>

#include "Storage.h"

//! Speicherzelle
/*!
 * Kapselung der Speicherzelle zur Verwendung innerhalb der Operationen.
 */
class StorageCell
{
private:
    Storage values;
    unsigned char type;
public:
    static const unsigned char Unused  = 0;
    static const unsigned char Integer = 1;
    static const unsigned char Float   = 2;
    static const unsigned char Binary  = 3;

    StorageCell();

    void setBinary(QString);
    void setInt(int);
    void setFloat(double);
    void setRaw(Storage, const unsigned char);

    QString getBinary();
    int getInt();
    double getFloat();
    Storage getRaw();

    const unsigned char getType();
};

#endif /*STORAGECELL_H_*/
