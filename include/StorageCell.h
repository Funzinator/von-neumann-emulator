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

    //! setzt die Speicherzelle auf den Binärwert s
    /*!
     * \param s Binärwert, wird in eine Festpunktzahl umgewandelt
     */
    void setBinary(QString);

    //! setzt die Speicherzelle auf die Festpunkzahl i
    /*!
     * \param i Festpunktzahlwert
     */
    void setInt(qint32);

    //! setzt die Speicherzelle auf die Gleitpunkzahl f
    /*!
     * \param f Gleitpunktzahlwert
     */
    void setFloat(float);

    //! setzt den Wert der Speicherzelle auf den einer anderen Speicherzelle values
    /*!
     * \param values Speicherzelle
     * \param type   Typ der Speicherzelle
     */
    void setRaw(Storage, const unsigned char);

    //! gibt den Wert der Speicherzelle, interpretiert als Binärwert, zurück
    /*!
     * \return Binärwert
     */
    QString getBinary();

    //! gibt den Wert der Speicherzelle, interpretiert als Festpunktzahl, zurück
    /*!
     * \return Festpunktzahlwert
     */    
    qint32 getInt();

    //! gibt den Wert der Speicherzelle, interpretiert als Gleitpunktzahl, zurück
    /*!
     * \return Gleitpunktzahlwert
     */
    float getFloat();

    //! gibt die Speicherzelle zurück
    /*!
     * \return Binärwert
     */    
    Storage getRaw();

    //! gibt den Typ der Speicherzelle zurück
    /*!
     * \return Typ der Speicherzelle
     */
    unsigned char getType();
};

#endif /*STORAGECELL_H_*/
