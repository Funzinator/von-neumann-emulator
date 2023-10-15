#ifndef STORAGE_H_
#define STORAGE_H_

#include <QtGlobal>

//! Datenstruktur der Speicherzelle
union Storage
{
    qint32 i; // garantiert 32 bit auf jeder von Qt unterstützten Plattform
    float f;  // per IEEE-754 Definition 32 bit auf jeder Plattform.
};

#endif /*STORAGE_H_*/
