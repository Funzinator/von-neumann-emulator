#include <QRandomGenerator>

#include "MainWindow.h"

QString version = "1.0";
QString autoren;
int jahr;

int main(int argc, char *argv[])
{
    QRandomGenerator qrand = QRandomGenerator(time(NULL));
    autoren = (qrand.generate() % 2 ? "C. Beppler, S. Jakobi" : "S. Jakobi, C. Beppler");
    jahr = QDate::currentDate().year();

    QApplication app(argc, argv);

    MainWindow *form = new MainWindow();
    form->show();

    return app.exec();
}
