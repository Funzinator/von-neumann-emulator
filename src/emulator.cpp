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

#include "ENA.h"
#include "ENAR.h"

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
        if (bbb == "ENA")
        {
            aaa = new ENA(zeilen[i]);
        }
        else if (bbb == "ENAR")
        {
            aaa = new ENAR(zeilen[i]);
        }
       
        op[zeilen[i]->LineNumber] = aaa;
    }

    Configuration *C;
    
    C = new Configuration();
    
    for (int j = 0; j < zeilen.count(); j++)
    {
        C->show();
        op[j]->run(C);
        std::cout << "-----------------------" << std::endl;
    }
    
    return 0;
}
