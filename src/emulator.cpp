#include <QRandomGenerator>
#if QT_VERSION >= 0x060500
#include <QStyleHints>
#endif

#include "MainWindow.h"

#include "info.h"

QString version;
QString autoren;
int jahr;

int main(int argc, char *argv[])
{
    QRandomGenerator qrand = QRandomGenerator(time(NULL));

    version = AppVersion;
    if (version.startsWith("v"))
    {
        version.remove(0, 1);
    }

    autoren = (qrand.generate() % 2 ? "C. Beppler, S. Jakobi" : "S. Jakobi, C. Beppler");
    jahr = QDate::currentDate().year();

    QApplication app(argc, argv);

#if QT_VERSION >= 0x060500
    /* See https://www.qt.io/blog/dark-mode-on-windows-11-with-qt-6.5 */
    MainWindow *form = new MainWindow(qApp->styleHints()->colorScheme());
#else
    MainWindow *form = new MainWindow();
#endif

    form->show();

    return app.exec();
}
