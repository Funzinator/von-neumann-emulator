#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow *form = new MainWindow();
    form->show();

    return app.exec();
}
