#include <iostream>

#include <QVector>
#include <QString>
#include <QFile>
#include <QMap>

#include "Parser.h"
#include "RawOperation.h"
#include "Operation.h"

#include <QApplication>
#include "MainWindow.h"
#include "CLI.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        QApplication app(argc, argv);
        MainWindow *form = new MainWindow();
    
        form->show();
        return app.exec();
    }
    else
    {
        QString filename(argv[1]);
        CLI *CommandLine = new CLI(filename);
        return 0;
    }
}
