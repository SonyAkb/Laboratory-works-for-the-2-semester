#ifndef MAIN_WINDOW_1_H
#define MAIN_WINDOW_1_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>
#include "house.h"
#include "prices.h"
#include "change_the_directory.h"
#include "save_data_window.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Main_Window_1; }
QT_END_NAMESPACE

class Main_Window_1 : public QMainWindow
{
    Q_OBJECT

public:
    Prices current_prices;//каталог цен
    House house_2;//дом,который собираю
    Main_Window_1(QWidget *parent = nullptr);
    ~Main_Window_1();

private slots:
    void on_calculate_but_clicked();
    void on_change_prices_but_clicked();
    void on_save_data_but_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_exit_clicked();
private:
    Ui::Main_Window_1 *ui;//главное окно
    change_the_directory *window_3;//изменить цены
    save_data_window *window_4;//сохранить данные
signals:
    void signal_1(Prices&);
    void signal_3(Prices&, House&);
public slots:
    void slot_2();
};
#endif // MAIN_WINDOW_1_H
