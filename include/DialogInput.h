#ifndef DIALOGINPUT_H_
#define DIALOGINPUT_H_

#include <QValidator>

#include "ui_DialogInput.h"

class DialogInput : public QDialog, public Ui::DialogInput
{
    Q_OBJECT

protected:
    void setValidator(const QValidator *v);

public:
    DialogInput(const QString &title, const QString &label, const QValidator *validator, QObject *parent);
};

#endif /*DIALOGINPUT_H_*/
