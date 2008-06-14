#ifndef GUIINTERFACE_H_
#define GUIINTERFACE_H_

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>

#include "CommunicationInterface.h"

class GuiInterface : public CommunicationInterface
{
private:
    QMainWindow *MainWindow;

public:
    GuiInterface(QMainWindow *);
    
    void sendSignal(unsigned char);
    void sendSignal(unsigned char, QString);
    void sendString(QString);
    QString receiveString(); /* deprecated */
    int receiveInteger();
    double receiveFloat();
    int receiveBinary();
};

#endif /*GUIINTERFACE_H_*/
