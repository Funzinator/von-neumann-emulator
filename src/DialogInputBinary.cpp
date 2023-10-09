#include "DialogInputBinary.h"

DialogInputBinary::DialogInputBinary(const QString &title, const QString &label, QObject *parent) : DialogInput(title, label, 0, parent)
{
    this->setValidator(new QRegularExpressionValidator(QRegularExpression("[01]+"), parent));
}
