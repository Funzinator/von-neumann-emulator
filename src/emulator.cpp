#include <iostream>

#include <QVector>
#include <QString>
#include <QFile>
#include <QMap>
#include <iostream>
#include <string>

#include "Parser.h"
#include "RawOperation.h"
#include "Operation.h"

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

#include <QApplication>
#include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *form = new MainWindow();
    
    form->show();
    return app.exec();
}
