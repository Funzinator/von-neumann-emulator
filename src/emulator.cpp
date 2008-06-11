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

using namespace std;

int main()
{
    QVector<RawOperation *> zeilen;
    
    QFile file("bla");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout << "Fehler" << endl;
    }

    Parser p;
    RawOperation *x = 0;
    
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

    Configuration *C;
    
    C = new Configuration();
    
    C->show();
    while (C->getPC() < zeilen.count()){
        zeilen[C->getPC()]->show();
        std::cout << "-----------------------" << std::endl;
        op[C->getPC()]->run(C);
        C->show();
    }

/*    for (int j = 0; j < zeilen.count(); j++)
    {
        op[j]->run(C);
        C->show();
        std::cout << "-----------------------" << std::endl;
    } (so geht UJP nicht) */
    
    return 0;
}
