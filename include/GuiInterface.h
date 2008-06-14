#ifndef GUIINTERFACE_H_
#define GUIINTERFACE_H_

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>

#include "CommunicationInterface.h"

class GuiInterface : public CommunicationInterface
{
    Q_OBJECT

private:
    QMainWindow *MainWindow;

public:
    GuiInterface(QMainWindow *);
    
    void sendSignal(unsigned char);
    void sendSignal(unsigned char, QString);
    void sendString(QString);
    int receiveInteger();
    double receiveFloat();
    int receiveBinary();
    
signals:
    void halt(QString);
    void stop(QString);
};

#endif /*GUIINTERFACE_H_*/
