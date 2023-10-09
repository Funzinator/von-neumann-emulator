#ifndef DIALOGINPUTINTEGER_H_
#define DIALOGINPUTINTEGER_H_

#include <QRegularExpressionValidator>

#include "DialogInput.h"

class DialogInputInteger : public DialogInput
{
    Q_OBJECT

public:
    DialogInputInteger(const QString &title, const QString &label, QObject *parent);
};

#endif /*DIALOGINPUTINTEGER_H_*/
