#include "DialogInput.h"

DialogInput::DialogInput(const QString &title, const QString &label, const QValidator *validator, QObject *parent) : QDialog()
{
    this->setupUi(this);

    this->setWindowTitle(title);
    this->labelInput->setText(label);
    this->setValidator(validator);
}

void DialogInput::setValidator(const QValidator *v)
{
    this->lineEditInput->setValidator(v);
}
