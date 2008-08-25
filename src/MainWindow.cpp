#include "MainWindow.h"

MainWindow::MainWindow() : QMainWindow()
{
    this->setupUi(this);

    this->i = 0;
    this->parser = 0;
    this->file = 0;

    this->timerRun = new QTimer(this);
    connect(this->timerRun, SIGNAL(timeout()), this, SLOT(timerNextStep()));

    /* Nur Zahlen (Integer und Float) für lineEditInput zulassen */ 
    QRegExp inputRegExp("-?([0-9]+|[0-9]*\\.[0-9]*)");
    QValidator *inputValidator = new QRegExpValidator(inputRegExp, this);
    this->lineEditInput->setValidator(inputValidator); 

    this->resetConfiguration();

    this->highlighter = new Highlighter(this->txtEditSourcecode->document());
}

MainWindow::~MainWindow()
{
    delete this->i;
    delete this->parser;
    delete this->file;
    delete this->timerRun;
    delete this->highlighter;
}

void MainWindow::resetConfiguration()
{
    this->lblOperation->setText(this->i ? this->i->getNextOperation(true) : "");
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
        case StorageCell::Integer:
            tmp.setNum(config->getAC()->getInt());
            break;

        case StorageCell::Float:
            tmp.setNum(config->getAC()->getFloat());
            break;

        case StorageCell::Binary:
            tmp = config->getAC()->getBinary();
            break;
    }
    this->lblAC->setText(tmp);

    this->lblPC->setText(QString("%1").arg(config->getPC()));
    this->lblSR->setText(QString("%1").arg(config->getSR()));
    
    for (int i = 0; i < Configuration::IndexRegisterCount; i++)
    {
        if (config->getIndexRegister(i)->getType() != StorageCell::Unused)
        {
            tmp.setNum(config->getIndexRegister(i)->getInt());
            this->listWidgetIndexregister->addItem(QString("%1: %2").arg(i).arg(tmp));
        }
    }
    
    QVector<unsigned int> usedSlots = config->getUsedData();
    for (int i = 0; i < usedSlots.size(); i++)
    {
        switch(config->getData(usedSlots[i])->getType())
        {
            case StorageCell::Integer:
                this->listWidgetData->addItem(QString("%1: %2\t[I]").arg(usedSlots[i]).arg(config->getData(usedSlots[i])->getInt()));
                break;

            case StorageCell::Float:
                this->listWidgetData->addItem(QString("%1: %2\t[F]").arg(usedSlots[i]).arg(config->getData(usedSlots[i])->getFloat()));
                break;

            case StorageCell::Binary:
                this->listWidgetData->addItem(QString("%1: %2\t[B]").arg(usedSlots[i]).arg(config->getData(usedSlots[i])->getBinary()));
                break;
        }
    }
}

void MainWindow::on_toolBtnNext_clicked()
{
    this->toolBtnStop->setEnabled(true);
    
    this->timerNextStep();
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

    this->listWidgetOutput->clear();
    this->on_txtEditSourcecode_textChanged();

    this->timerRun->stop();

    // FIXME: alles zurücksetzen
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

    this->listWidgetOutput->addItem(QString("System stopped%1").arg((message.length() ? QString(": %1").arg(message) : ".")));

    this->toolBtnPause->setEnabled(false);
    this->toolBtnPlay->setEnabled(false);
    this->toolBtnStop->setEnabled(true);
    this->toolBtnNext->setEnabled(false);

    this->txtEditSourcecode->setReadOnly(false);
}

void MainWindow::halt(QString message)
{
    this->timerRun->stop();

    this->listWidgetOutput->addItem(QString("System halted%1").arg((message.length() ? QString(": %1").arg(message) : ".")));

    QMessageBox::critical(this,
                          "Programmabbruch",
                          message,
                          QMessageBox::Ok);

    this->toolBtnPause->setEnabled(false);
    this->toolBtnPlay->setEnabled(false);
    this->toolBtnStop->setEnabled(true);
    this->toolBtnNext->setEnabled(false);

    this->txtEditSourcecode->setReadOnly(false);
}

void MainWindow::on_actionNew_activated()
{
    this->txtEditSourcecode->setPlainText("");
    this->listWidgetOutput->clear();
    this->listWidgetInput->clear();

    if (this->file)
    {
        delete this->file;
    }
    this->file = 0;
}

void MainWindow::on_actionOpen_activated()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "von-Neumann-Programm öffnen",
                                                    "",
                                                    "Alle Dateien (*)");
    if (filename.length())
    {
        if (this->file)
        {
            delete this->file;
        }
        this->file = new QFile(filename);

        QFile file(filename);
        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            this->txtEditSourcecode->setPlainText(file.readAll());
        }
    }
}

void MainWindow::on_actionSave_activated()
{
    if (this->file)
    {
        QFile file(this->file->fileName());
        if (file.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream ts(&file);
            ts << this->txtEditSourcecode->toPlainText();
        }
    }
}

void MainWindow::on_actionSaveAs_activated()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    "von-Neumann-Programm speichern",
                                                    "",
                                                    "Alle Dateien (*)");
    if (filename.length())
    {
        if (this->file)
        {
            delete this->file;
        }
        this->file = new QFile(filename);

        QFile file(filename);
        if (file.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream ts(&file);
            ts << this->txtEditSourcecode->toPlainText();
        }
    }
}

void MainWindow::on_txtEditSourcecode_textChanged()
{
    this->timerRun->stop();

    if (!this->parser)
    {
        this->parser = new Parser;
    }

    if (this->i)
    {
        delete this->i;
        this->i = 0;
    }

    this->toolBtnPause->setEnabled(false);
    this->toolBtnPlay->setEnabled(true);
    this->toolBtnStop->setEnabled(false);
    this->toolBtnNext->setEnabled(true);

    this->i = new Interpreter(this->parser->Parse(this->txtEditSourcecode->toPlainText()), new Configuration(new GuiInterface(this, this->listWidgetInput, this->listWidgetOutput)));

    this->resetConfiguration();
}

void MainWindow::on_lineEditInput_returnPressed()
{
    if (this->lineEditInput->hasAcceptableInput())
    {
        this->listWidgetInput->addItem(this->lineEditInput->text());
        this->lineEditInput->clear();
    }
}

void MainWindow::on_toolBtnNumber_clicked()
{
    QString line, out, tmp(this->txtEditSourcecode->toPlainText());
    QStringList list = tmp.split("\n", QString::SkipEmptyParts);

    int comments = 0;
    for (int i = 0; i < list.size(); i++)
    {
        line = list.at(i);
        if (!line.contains(QRegExp("^\\s*\\{")))
        {
            out += tmp.setNum(i - comments) + ": " + line.remove(QRegExp("^\\s*[0-9]+\\s*:\\s*"));
        }
        else
        { 
            out += line;
            comments++;
        }
        out += "\n";
    }
    this->txtEditSourcecode->setPlainText(out);
}

void MainWindow::on_toolBtnClearInput_clicked()
{
    this->listWidgetInput->clear();
}

void MainWindow::on_toolBtnOpenInput_clicked()
{
    // FIXME: implementieren!
}
