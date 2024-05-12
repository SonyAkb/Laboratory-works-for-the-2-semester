#include "main_window_1.h"
#include <QApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(QCoreApplication::applicationDirPath() + "/additional_files/styles.css");
    if (file.exists()) {
        file.open(QFile::ReadOnly | QFile::Text);
        QTextStream stream(&file);
        a.setStyleSheet(stream.readAll());
        file.close();
    } else {
        qWarning() << "Unable to open file styles.qss";
    }

    Main_Window_1 w;
    w.show();

    return a.exec();
}
