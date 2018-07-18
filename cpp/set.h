#ifndef SET_H
#define SET_H

#include <QMainWindow>

namespace Ui {
class Set;
}

class Set : public QMainWindow
{
    Q_OBJECT

public:
    explicit Set(QWidget *parent = 0);

    ~Set();

private slots:


    void on_comboBox_3_currentIndexChanged(int None);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_buttonBox_rejected();

    //void setValue(int);
    // void setUpPage();


    void on_checkBox_2_clicked();


    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_12_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Set *ui;
};

#endif // SET_H
