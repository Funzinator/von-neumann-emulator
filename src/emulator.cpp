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
    QApplication app(argc, argv);

    if (argc == 1)
    {
        MainWindow *form = new MainWindow();
        form->show();
    }
    else
    {
        QString filename(argv[1]);
        CLI *CommandLine = new CLI(filename);
        
        CommandLine->run();
    }

    return app.exec();
}
