#ifndef ABOUTDIALOG_H_
#define ABOUTDIALOG_H_

#include "ui_AboutDialog.h"

extern QString version;
extern QString autoren;
extern int jahr;

class AboutDialog : public QDialog, public Ui::AboutDialog
{
    Q_OBJECT

public:
    AboutDialog();
};

#endif /*ABOUTDIALOG_H_*/
