#ifndef CHANGE_THE_DIRECTORY_H
#define CHANGE_THE_DIRECTORY_H

#include <QDialog>
#include <QWidget>
#include "prices.h"
namespace Ui {
class change_the_directory;
}

class change_the_directory : public QDialog
{
    Q_OBJECT

public:
    explicit change_the_directory(QWidget *parent = nullptr);
    ~change_the_directory();
private:
    Ui::change_the_directory *ui;
public slots:
    void slot_1(Prices& catalog_1);
private slots:
    void on_pushButton_change_cost_clicked();
    void on_pushButton_cansel_clicked();
signals:
    void signal_2();
};

#endif // CHANGE_THE_DIRECTORY_H
