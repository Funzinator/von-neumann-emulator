#include "GuiInterface.h"

GuiInterface::GuiInterface(QMainWindow *MainWindow) : CommunicationInterface()
{
    this->MainWindow = MainWindow;
}

void GuiInterface::sendSignal(unsigned char)
{
    
}

void GuiInterface::sendSignal(unsigned char, QString)
{

}

void GuiInterface::sendString(QString message)
{
    /* wird später durch Ausgabeband ersetzt */
    QMessageBox::information(this->MainWindow,
                             "Ausgabe",
                             message,
                             QMessageBox::Ok);
}

/* deprecated */
QString GuiInterface::receiveString()
{
    return QInputDialog::getText(this->MainWindow,
                                 "Eingabe",
                                 "Eingabe:",
                                 QLineEdit::Normal);
}

int GuiInterface::receiveInteger()
{

}

double GuiInterface::receiveFloat()
{

}

int GuiInterface::receiveBinary()
{

}
