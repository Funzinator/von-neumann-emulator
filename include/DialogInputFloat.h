#ifndef DIALOGINPUTFLOAT_H_
#define DIALOGINPUTFLOAT_H_

#include <QRegularExpressionValidator>

#include "DialogInput.h"

class DialogInputFloat : public DialogInput
{
    Q_OBJECT

public:
    DialogInputFloat(const QString &title, const QString &label, QObject *parent);
};

#endif /*DIALOGINPUTFLOAT_H_*/
