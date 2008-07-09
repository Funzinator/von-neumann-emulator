#include "MainWindow.h"

MainWindow::MainWindow() : QMainWindow()
{
    this->setupUi(this);

    this->i = 0;
    this->parser = 0;
    this->file = 0;
    
    this->timerRun = new QTimer(this);
    connect(this->timerRun, SIGNAL(timeout()), this, SLOT(timerNextStep()));

    this->resetConfiguration();
    
    this->highlighter = new Highlighter(this->txtEditSourcecode->document());
    
    this->sourcecodeEdited = false;
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
    this->lblOperation->setText(this->i->getNextOperation(true));
    
    for (int i = 0; i < Configuration::IndexRegisterCount; i++)
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
                    
                case StorageCell::Unused:
                    tmp = "NULL";
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

    this->txtEditSourcecode->setReadOnly(false);

    this->timerRun->stop();
}

void MainWindow::on_toolBtnPlay_clicked()
{
    this->toolBtnPlay->setEnabled(false);
    this->toolBtnNext->setEnabled(false);
    this->toolBtnPause->setEnabled(true);
    this->toolBtnStop->setEnabled(true);

    this->txtEditSourcecode->setReadOnly(true);

    this->timerRun->start(100);
}

void MainWindow::on_toolBtnStop_clicked()
{
    this->toolBtnStop->setEnabled(false);
    this->toolBtnPause->setEnabled(false);
    this->toolBtnPlay->setEnabled(true);
    this->toolBtnNext->setEnabled(true);

    this->txtEditSourcecode->setReadOnly(false);

    this->timerRun->stop();

    /* FIXME: alles zurücksetzen */    
    this->resetConfiguration();
}

void MainWindow::timerNextStep()
{
    this->i->next();
    this->showConfiguration(this->i->getConfiguration());  
}

void MainWindow::stop(QString message)
{
    this->timerRun->stop();
    
    QMessageBox::information(this,
                             "Programm terminierte ohne Fehler",
                             message,
                             QMessageBox::Ok);
}

void MainWindow::halt(QString message)
{
    QMessageBox::critical(this,
                          "Programm terminierte mit Fehler",
                          message,
                          QMessageBox::Ok);
}

void MainWindow::on_actionOpen_activated()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "von-Neumann-Programm öffnen",
                                                    "",
                                                    "Alle Dateien (*)");
    if (filename != "")
    {
        if (this->parser == 0)
        {
            this->parser = new Parser;
        }
        
        if (this->file != 0)
        {
            delete this->file;
        }
        this->file = new QFile(filename);

        if (this->i != 0)
        {
            delete this->i;
            this->i = 0;
        }
        this->i = new Interpreter(this->parser->Parse(this->file), new Configuration(new GuiInterface(this)));

        this->toolBtnPlay->setEnabled(true);
        this->toolBtnNext->setEnabled(true);
        
        QFile file(filename);
        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            this->txtEditSourcecode->setPlainText(file.readAll());
            this->sourcecodeEdited = false;
        }
    }
}
#include <iostream>
void MainWindow::on_txtEditSourcecode_textChanged()
{
    if (this->sourcecodeEdited == false)
    {
        this->sourcecodeEdited = true;
        std::cout << this->txtEditSourcecode->toPlainText().toStdString() << std::endl;
    }
}
