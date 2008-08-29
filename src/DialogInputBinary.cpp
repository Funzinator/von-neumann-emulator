#include "DialogInputBinary.h"

DialogInputBinary::DialogInputBinary(const QString &title, const QString &label, QObject *parent) : DialogInput(title, label, 0, parent)
{
    this->setValidator(new QRegExpValidator(QRegExp("[01]+"), parent));
}
