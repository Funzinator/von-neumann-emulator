#ifndef DIALOGINPUTBINARY_H_
#define DIALOGINPUTBINARY_H_

#include <QRegExpValidator>

#include "DialogInput.h"

class DialogInputBinary : public DialogInput
{
    Q_OBJECT

public:
    DialogInputBinary(const QString &title, const QString &label, QObject *parent);
};

#endif /*DIALOGINPUTBINARY_H_*/
