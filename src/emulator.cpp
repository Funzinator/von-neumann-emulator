#include "MainWindow.h"

QString version = "1.0rc1";
QString autoren;

int main(int argc, char *argv[])
{
    qsrand (time(NULL));
    autoren = (qrand() % 2 ? "C. Beppler, S. Jakobi" : "S. Jakobi, C. Beppler");

    QApplication app(argc, argv);

    MainWindow *form = new MainWindow();
    form->show();

    return app.exec();
}
