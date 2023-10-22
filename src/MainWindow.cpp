#include "MainWindow.h"

#if QT_VERSION >= 0x060500
MainWindow::MainWindow(Qt::ColorScheme colorScheme) : QMainWindow()
#else
MainWindow::MainWindow() : QMainWindow()
#endif
{
    this->setupUi(this);
    this->setWindowTitle("von-Neumann-Emulator (untitled*)");
    this->i = 0;
    this->parser = 0;
    this->file = 0;
#if QT_VERSION >= 0x060500
    this->colorScheme = colorScheme;
#endif

#ifdef Q_OS_WASM
    QAction *action;
    foreach (action, this->menuFile->actions()) {
        if (action->text() != "&Beenden") {
            this->menuFile->removeAction(action);
        }
    }
#endif

    this->timerRun = new QTimer(this);
    connect(this->timerRun, SIGNAL(timeout()), this, SLOT(timerNextStep()));

    connect(this->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    /* Nur Zahlen (Integer und Float) für lineEditInput zulassen */ 
    this->inputRegExp = new QRegularExpression(INPUT_REGEXP);
    QValidator *inputValidator = new QRegularExpressionValidator(*this->inputRegExp, this);
    this->lineEditInput->setValidator(inputValidator);

    this->waitForInputState = CommunicationInterface::STATE_NO_WAIT;

    this->resetConfiguration();

#if QT_VERSION >= 0x060500
    this->highlighter = new Highlighter(this->txtEditSourcecode->document(), colorScheme);
#else
    this->highlighter = new Highlighter(this->txtEditSourcecode->document());
#endif

    this->aboutDialog = 0;
}

MainWindow::~MainWindow()
{
    delete this->i;
    delete this->parser;
    delete this->file;
    delete this->timerRun;
    delete this->highlighter;
    delete this->aboutDialog;
}

#ifndef Q_OS_WASM
void MainWindow::closeEvent(QCloseEvent *event)
{
    if (this->txtEditSourcecode->document()->isModified())
    {
        switch (saveChanges())
        {
            case QMessageBox::Yes:
                this->on_actionSave_triggered();
                /* FALLTHRU */
            case QMessageBox::No:
                event->accept();
                break;
            case QMessageBox::Cancel:
                event->ignore();
                break;
        }
    }
}
#endif

#ifndef Q_OS_WASM
int MainWindow::saveChanges()
{
    QMessageBox msgBxSave;
    msgBxSave.setWindowTitle("Unsaved changes");
    msgBxSave.setText("Code has been modified. Save changes?");
    msgBxSave.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    return msgBxSave.exec();
}
#endif

void MainWindow::resetConfiguration()
{
    this->lblOperation->setText(this->i ? this->i->getNextOperation(true) : "");
    this->lblAC->setText("0");
    this->lblPC->setText("0");
    this->lblSR->setText("-");

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

    if (config->isEmptySR())
    {
        this->lblSR->setText("-");
    }
    else
    {
        QVector<unsigned int> SRStackContent = config->getSRStackContent();
        int n = SRStackContent.size();
        int l = (n<MainWindow::MaxVisibleStack ?  n : MainWindow::MaxVisibleStack);
        tmp.setNum(SRStackContent.at(n-1));
        if (l > 1)
        {
            for (int i = 2 ; i <= l; i++)
            {
                tmp += QString("|%1").arg(SRStackContent.at(n-i));
            }
            if (l < n)
            {
                tmp += "|...";
            }
        }
        this->lblSR->setText(tmp);
    }

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

#ifndef Q_OS_WASM
    QMessageBox::critical(this,
                          "Programmabbruch",
                          message,
                          QMessageBox::Ok);
#endif

    this->toolBtnPause->setEnabled(false);
    this->toolBtnPlay->setEnabled(false);
    this->toolBtnStop->setEnabled(true);
    this->toolBtnNext->setEnabled(false);

    this->txtEditSourcecode->setReadOnly(false);
}

void MainWindow::requestInput(QString type)
{
    if (this->timerRun->isActive())
    {
        this->timerRun->stop();
        this->waitForInputState = CommunicationInterface::STATE_WAIT_RUN;
    }
    else
    {
        this->waitForInputState = CommunicationInterface::STATE_WAIT_STEP;
    }

    QFont font;
    font.setBold(true);

    QListWidgetItem *item = new QListWidgetItem();
    item->setText(QString("Waiting for %1...").arg(type));
    item->setFont(font);

    this->listWidgetOutput->addItem(item);

    this->toolBtnPause->setEnabled(false);
    this->toolBtnPlay->setEnabled(false);
    this->toolBtnStop->setEnabled(true);
    this->toolBtnNext->setEnabled(false);

    this->txtEditSourcecode->setReadOnly(true);

    this->lineEditInput->setFocus();
}

#ifndef Q_OS_WASM
void MainWindow::on_actionNew_triggered()
{
    if (this->txtEditSourcecode->document()->isModified())
    {
        switch (saveChanges())
        {
            case QMessageBox::Yes:
                this->on_actionSave_triggered();
            case QMessageBox::No:
                break;
            case QMessageBox::Cancel:
                return;
        }
    }

    this->txtEditSourcecode->setPlainText("");
    this->listWidgetOutput->clear();
    this->listWidgetInput->clear();

    if (this->file)
    {
        delete this->file;
    }
    this->file = 0;
    this->setWindowTitle("von-Neumann-Emulator (untitled*)");
}
#endif

#ifndef Q_OS_WASM
void MainWindow::on_actionOpen_triggered()
{
    if (this->txtEditSourcecode->document()->isModified())
    {
        switch (saveChanges())
        {
            case QMessageBox::Yes:
                this->on_actionSave_triggered();
            case QMessageBox::No:
                break;
            case QMessageBox::Cancel:
                return;
        }
    }

    QString filename = QFileDialog::getOpenFileName(this,
                                                    QString::fromUtf8("von-Neumann-Programm öffnen"),
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
        this->setWindowTitle("von-Neumann-Emulator ("+filename+")");
    }
}
#endif

#ifndef Q_OS_WASM
void MainWindow::on_actionSave_triggered()
{
    if (this->file)
    {
        QFile file(this->file->fileName());
        if (file.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream ts(&file);
            ts << this->txtEditSourcecode->toPlainText();
            this->txtEditSourcecode->document()->setModified(false);
            this->setWindowTitle("von-Neumann-Emulator ("+this->file->fileName()+")");
        }
    }
    else
    {
        this->on_actionSaveAs_triggered();
    }
}
#endif

#ifndef Q_OS_WASM
void MainWindow::on_actionSaveAs_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    QString::fromUtf8("von-Neumann-Programm speichern"),
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
            this->txtEditSourcecode->document()->setModified(false);
            this->setWindowTitle("von-Neumann-Emulator ("+this->file->fileName()+")");
        }
    }
}
#endif

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
    
    if ( (this->file) && (this->txtEditSourcecode->document()->isModified()) )
    {
        this->setWindowTitle("von-Neumann-Emulator ("+this->file->fileName()+"*)");
    }
}

void MainWindow::on_lineEditInput_returnPressed()
{
    if (this->lineEditInput->hasAcceptableInput())
    {
        this->listWidgetInput->addItem(this->lineEditInput->text());
        this->lineEditInput->clear();
        if (this->waitForInputState != CommunicationInterface::STATE_NO_WAIT)
        {
            this->toolBtnPause->setEnabled(true);
            this->toolBtnPlay->setEnabled(false);
            this->toolBtnStop->setEnabled(true);
            this->toolBtnNext->setEnabled(true);

            this->txtEditSourcecode->setReadOnly(false);

            if (this->listWidgetOutput->count() > 0)
            {
                delete this->listWidgetOutput->takeItem(this->listWidgetOutput->count() - 1);
            }

            this->timerNextStep();
            if (this->waitForInputState == CommunicationInterface::STATE_WAIT_RUN)
            {
                this->timerRun->start();
            }
            this->waitForInputState = CommunicationInterface::STATE_NO_WAIT;
        }
    }
}

void MainWindow::on_toolBtnNumber_clicked()
{
    QString line, out, tmp, old(this->txtEditSourcecode->toPlainText());
    QStringList list = old.split("\n", Qt::SkipEmptyParts);
    bool modif;

    int comments = 0;
    for (int i = 0; i < list.size(); i++)
    {
        line = list.at(i);
        if (!line.contains(QRegularExpression("^\\s*\\{")))
        {
            out += tmp.setNum(i - comments) + ": " + line.remove(QRegularExpression("^\\s*[0-9]+\\s*:\\s*"));
        }
        else
        { 
            out += line;
            comments++;
        }
        out += "\n";
    }
    //setPlaintext() sets modified false... Therefore:
    modif = this->txtEditSourcecode->document()->isModified();
    
    this->txtEditSourcecode->setPlainText(out);
    
    //if nothing changed and isModified==false, do not change Title
    if ( (old == out) && (! modif) && this->file )
    {
        this->setWindowTitle("von-Neumann-Emulator ("+this->file->fileName()+")");
    }
    //else: set modified true [again]
    else
    {
        this->txtEditSourcecode->document()->setModified(true);
    }
}

void MainWindow::on_toolBtnClearInput_clicked()
{
    this->listWidgetInput->clear();
}

void MainWindow::on_toolBtnOpenInput_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    QString::fromUtf8("Eingabeband öffnen"),
                                                    "",
                                                    "Alle Dateien (*)");
    if (filename.length())
    {
        QFile file(filename);
        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            QString line;

            while (!file.atEnd())
            {
                line = file.readLine().simplified();

                if (this->inputRegExp->match(line).hasMatch())
                {
                    this->listWidgetInput->addItem(line);
                }
            }
        }
    }
}

void MainWindow::on_actionAbout_triggered()
{
    if (!this->aboutDialog)
    {
        this->aboutDialog = new AboutDialog;
    }

    this->aboutDialog->show();
}
