#ifndef GUIINTERFACE_H_
#define GUIINTERFACE_H_

#include <QMainWindow>
#include <QListWidget>
#include <QInputDialog>
#include <QString>

#include "CommunicationInterface.h"

class GuiInterface : public CommunicationInterface
{
    Q_OBJECT

private:
    QMainWindow *MainWindow;
    QListWidget *listWidgetInput;
    QListWidget *listWidgetOutput;

public:
    GuiInterface(QMainWindow *, QListWidget*, QListWidget *);
    
    void sendSignal(unsigned char);
    void sendSignal(unsigned char, QString);
    void sendString(QString);
    int receiveInteger();
    double receiveFloat();
    QString receiveBinary();
    
signals:
    void halt(QString);
    void stop(QString);
};

#endif /*GUIINTERFACE_H_*/
