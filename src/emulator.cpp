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
