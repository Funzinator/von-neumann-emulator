#include "MainWindow.h"

MainWindow::MainWindow() : QMainWindow()
{
    this->setupUi(this);

    this->timerRun = new QTimer(this);
    connect(this->timerRun, SIGNAL(timeout()), this, SLOT(timerNextStep()));

    this->resetConfiguration();

    /* Replace me */
    QFile *file = new QFile("bla");

    Parser p;
    this->i = new Interpreter(p.Parse(file), new Configuration(new GuiInterface()));
}

void MainWindow::resetConfiguration()
{
    this->lblOperation->setText("");
    this->lblAC->setText("0");
    this->lblPC->setText("0");
    this->lblSR->setText("0");

    this->listWidgetData->clear();
    this->listWidgetIndexregister->clear();
}

void MainWindow::showConfiguration(Configuration *config)
{
    this->resetConfiguration();
    QString tmp;

    switch(config->getAC()->getType())
    {
        /* FIXME: Evtl. Icon für Typ setzen (in GUI ermöglichen) */
        case StorageCell::Integer:
            tmp.setNum(config->getAC()->getInt());
            break;

        case StorageCell::Float:
            tmp.setNum(config->getAC()->getFloat()); /* FIXME: testen */
            break;

        case StorageCell::Binary:
            tmp.setNum(config->getAC()->getInt()); /* vielleicht umwandeln, dann aber bereits in StorageCell */
            break;
    }
    this->lblAC->setText(tmp);
    this->lblPC->setNum((int)config->getPC()); /* caste nach int... vielleicht sollten wir den Typ generell ändern */
    this->lblSR->setNum((int)config->getSR());
    
    for (int i = 0; i < 16; i++) /* FIXME auslagern in Konstante */
    {
        if (config->getIndexRegister(i) != 0)
        {
            switch(config->getIndexRegister(i)->getType())
            {
                /* FIXME: Typen setzen */
                case StorageCell::Integer:
                    tmp.setNum(config->getIndexRegister(i)->getInt());
                    break;
    
                case StorageCell::Float:
                    tmp.setNum(config->getIndexRegister(i)->getFloat()); /* FIXME: testen */
                    break;
    
                case StorageCell::Binary:
                    tmp.setNum(config->getIndexRegister(i)->getInt()); /* vielleicht umwandeln, dann aber bereits in StorageCell */
                    break;     
            }
            this->listWidgetIndexregister->addItem(QString("%1: %2").arg(i).arg(tmp));
        }
    }
    
    QVector<unsigned int> usedSlots = config->getUsedData();
    for (int i = 0; i < usedSlots.size(); i++)
    {
        this->listWidgetData->addItem(QString("%1: %2").arg(usedSlots[i]).arg(config->getData(usedSlots[i])->getInt()));
    }
}

void MainWindow::on_toolBtnNext_clicked()
{
    this->toolBtnStop->setEnabled(true);
    
    this->i->next();
    this->showConfiguration(this->i->getConfiguration());
}

void MainWindow::on_toolBtnPause_clicked()
{
    this->toolBtnPause->setEnabled(false);
    this->toolBtnPlay->setEnabled(true);
    this->toolBtnStop->setEnabled(true);
    this->toolBtnNext->setEnabled(true);
    
    this->timerRun->stop();
}

void MainWindow::on_toolBtnPlay_clicked()
{
    this->toolBtnPlay->setEnabled(false);
    this->toolBtnNext->setEnabled(false);
    this->toolBtnPause->setEnabled(true);
    this->toolBtnStop->setEnabled(true);
 
    this->timerRun->start(100);
}

void MainWindow::on_toolBtnStop_clicked()
{
    this->toolBtnStop->setEnabled(false);
    this->toolBtnPause->setEnabled(false);
    this->toolBtnPlay->setEnabled(true);
    this->toolBtnNext->setEnabled(true);
    
    this->timerRun->stop();

    /* FIXME: alles zurücksetzen */    
    this->resetConfiguration();
}

void MainWindow::timerNextStep()
{
    this->i->next();
    this->showConfiguration(this->i->getConfiguration());  
}
