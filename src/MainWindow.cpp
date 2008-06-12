#include "MainWindow.h"

#include <QFile>
#include "Parser.h"
#include"ADA.h"
#include"ADI.h"
#include"AZJEQ.h"
#include"AZJGE.h"
#include"AZJGR.h"
#include"AZJLE.h"
#include"AZJLS.h"
#include"AZJNE.h"
#include"DVA.h"
#include"ENA.h"
#include"ENAI.h"
#include"ENAR.h"
#include"ENI.h"
#include"ENIA.h"
#include"ENTIER.h"
#include"FAD.h"
#include"FDV.h"
#include"FMU.h"
#include"FNG.h"
#include"FSB.h"
#include"IRE.h"
#include"LDA.h"
#include"MDA.h"
#include"MUA.h"
#include"NGA.h"
#include"NOP.h"
#include"SBA.h"
#include"SBI.h"
#include"SRJ.h"
#include"SRR.h"
#include"STA.h"
#include"UJP.h"


MainWindow::MainWindow() : QMainWindow()
{
    this->timerRun = new QTimer(this);
    this->setupUi(this);
 
    connect(this->timerRun, SIGNAL(timeout()), this, SLOT(timerNextStep()));

    this->resetConfiguration();

    this->toolBtnPause->setEnabled(false);
    this->toolBtnStop->setEnabled(false);

    /* Remove me */

    QFile file("bla");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    Parser p;
    RawOperation *x = 0;
    QVector<RawOperation *> zeilen;

    while (!file.atEnd())
    {
        QString line = file.readLine();

        if ((x = p.convertLine(line)))
        {
            /* Zeile gültig */
            zeilen.append(x);
        }
    }

    QMap<unsigned int,Operation *> op;

    /* DAS MUSS IN EINE EIGENE KLASSE ODER SO... MACHE ICH SPÄTER */
    Operation *aaa = 0;
    QString bbb;
    int i;
    for (i = 0; i < zeilen.count(); i++)
    {
        bbb = zeilen[i]->Operator;

        /* es ist und bleibt unvermeidlich */
        if (bbb == "ADA")
        {
            aaa = new ADA(zeilen[i]);
        }
        else if (bbb == "ADI")
        {
            aaa = new ADI(zeilen[i]);
        }
        else if (bbb == "AZJ,EQ")
        {
            aaa = new AZJEQ(zeilen[i]);
        }
        else if (bbb == "AZJ,GE")
        {
            aaa = new AZJGE(zeilen[i]);
        }
        else if (bbb == "AZJ,GR")
        {
            aaa = new AZJGR(zeilen[i]);
        }
        else if (bbb == "AZJ,LE")
        {
            aaa = new AZJLE(zeilen[i]);
        }
        else if (bbb == "AZJ,LS")
        {
            aaa = new AZJLS(zeilen[i]);
        }
        else if (bbb == "AZJ,NE")
        {
            aaa = new AZJNE(zeilen[i]);
        }
        else if (bbb == "DVA")
        {
            aaa = new DVA(zeilen[i]);
        }
        else if (bbb == "ENA")
        {
            aaa = new ENA(zeilen[i]);
        }
        else if (bbb == "ENAI")
        {
            aaa = new ENAI(zeilen[i]);
        }
        else if (bbb == "ENAR")
        {
            aaa = new ENAR(zeilen[i]);
        }
        else if (bbb == "ENI")
        {
            aaa = new ENI(zeilen[i]);
        }
        else if (bbb == "ENTIER")
        {
            aaa = new ENTIER(zeilen[i]);
        }
        else if (bbb == "FAD")
        {
            aaa = new FAD(zeilen[i]);
        }
        else if (bbb == "FDV")
        {
            aaa = new FDV(zeilen[i]);
        }
        else if (bbb == "FMU")
        {
            aaa = new FMU(zeilen[i]);
        }
        else if (bbb == "FNG")
        {
            aaa = new FNG(zeilen[i]);
        }
        else if (bbb == "FSB")
        {
            aaa = new FSB(zeilen[i]);
        }
        else if (bbb == "IRE")
        {
            aaa = new IRE(zeilen[i]);
        }
        else if (bbb == "LDA")
        {
            aaa = new LDA(zeilen[i]);
        }
        else if (bbb == "MDA")
        {
            aaa = new MDA(zeilen[i]);
        }
        else if (bbb == "MUA")
        {
            aaa = new MUA(zeilen[i]);
        }
        else if (bbb == "NGA")
        {
            aaa = new NGA(zeilen[i]);
        }
        else if (bbb == "NOP")
        {
            aaa = new NOP(zeilen[i]);
        }
        else if (bbb == "SBA")
        {
            aaa = new SBA(zeilen[i]);
        }
        else if (bbb == "SBI")
        {
            aaa = new SBI(zeilen[i]);
        }
        else if (bbb == "SRJ")
        {
            aaa = new SRJ(zeilen[i]);
        }
        else if (bbb == "SRR")
        {
            aaa = new SRR(zeilen[i]);
        }
        else if (bbb == "STA")
        {
            aaa = new STA(zeilen[i]);
        }
        else if (bbb == "UJP")
        {
            aaa = new UJP(zeilen[i]);
        }
        else if (bbb == "ENAR")
        {
            aaa = new ENAR(zeilen[i]);
        }

        op[zeilen[i]->LineNumber] = aaa;
    }
    /* DAS BLEIBT HIER ;-) */

    this->i = new Interpreter(op, 0);
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
