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

    //QPalette palette = a.palette();// Получаем палитру приложения
    //palette.setColor(QPalette::Window, QColor("light blue"));// Устанавливаем новый фоновый цвет
    //palette.setColor(QPalette::Text, QColor("dark blue"));// Устанавливаем новый цвет текста
    //a.setPalette(palette);// Устанавливаем новую палитру для всего приложения

    //QFont font;
    //font.setFamily("Arial"); // Или другой семейство шрифтов
    //font.setPointSize(12);   // Размер шрифта
    //a.setFont(font);

    return a.exec();
}
