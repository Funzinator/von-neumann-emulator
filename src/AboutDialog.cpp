#include "AboutDialog.h"

AboutDialog::AboutDialog() : QDialog()
{
    this->setupUi(this);
    this->labelDescription->setText(this->labelDescription->text().arg(version).arg(autoren).arg(jahr));
}
