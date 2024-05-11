#ifndef SAVE_DATA_WINDOW_H
#define SAVE_DATA_WINDOW_H

#include <QDialog>
#include <QFileDialog>
#include "house.h"
#include "prices.h"

namespace Ui {
class save_data_window;
}

class save_data_window : public QDialog
{
    Q_OBJECT

public:
    explicit save_data_window(QWidget *parent = nullptr);
    ~save_data_window();

private:
    Ui::save_data_window *ui;


public slots:
    void slot_3(Prices& catalog_3, House& house_3);
private slots:
    void on_pushButton_cansel_clicked();
    void on_pushButton_save_clicked();
};

#endif // SAVE_DATA_WINDOW_H
