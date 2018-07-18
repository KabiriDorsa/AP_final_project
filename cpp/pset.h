#ifndef PSET_H
#define PSET_H

#include <QMainWindow>

namespace Ui {
class pset;
}

class pset : public QMainWindow
{
    Q_OBJECT


private slots:


    void on_comboBox_30_currentIndexChanged(int None);

    void on_comboBox_100_currentIndexChanged(int index);

    void on_comboBox_20_currentIndexChanged(int index);


    void on_pushButton_100_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_30_clicked();

    void on_buttonBox_rejected();

    //void setValue(int);
    // void setUpPage();


    void on_checkBox_20_clicked();


    void on_pushButton_130_clicked();

    void on_pushButton_140_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_150_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_70_clicked();

    void on_pushButton_80_clicked();

    void on_pushButton_90_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_160_clicked();

    void on_pushButton_120_clicked();


    void on_buttonBox_accepted();

public:
    explicit pset(QWidget *parent = 0);
    ~pset();

private:
    Ui::pset *ui;
};

#endif // PSET_H




