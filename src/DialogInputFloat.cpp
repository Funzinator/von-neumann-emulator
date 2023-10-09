#include "DialogInputFloat.h"

DialogInputFloat::DialogInputFloat(const QString &title, const QString &label, QObject *parent) : DialogInput(title, label, 0, parent)
{
    this->setValidator(new QRegularExpressionValidator(QRegularExpression("[-+]?([0-9]*\\.?[0-9]*)"), parent));
}
