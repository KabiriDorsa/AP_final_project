#ifndef PERSIAN_H
#define PERSIAN_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDirModel>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include "pset.h"
#include<string>
#include <iostream>
#include <QFileSystemModel>
#include <QVBoxLayout>
#include <QAbstractItemModel>
#include <QListWidgetItem>

namespace Ui {
class persian;
}

class persian : public QMainWindow
{
    Q_OBJECT

public:
    explicit persian(QWidget *parent = 0);
    ~persian();

private slots:

    void on_pushButton_37_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_39_clicked();
    void on_pushButton_40_clicked();
    void on_toolButton_67_clicked();
    void on_button_7_clicked();
    void on_toolButton_68_clicked();
    void on_toolButton_73_clicked();
    void on_pushButton_41_clicked();
    void on_toolButton_71_clicked();
    void on_toolButton_69_clicked();
    void on_toolButton_70_clicked();
    void on_pushButton_42_clicked();

    void on_listWidget_13_itemClicked(QListWidgetItem *item);

    void on_listWidget_14_itemClicked(QListWidgetItem *item);


    void on_action_3_triggered();

    void on_action_7_triggered();

    void on_action_10_triggered();

    void on_action_11_triggered();

    void on_action_13_triggered();

    void on_action_14_triggered();

    void on_action_15_triggered();

    void on_action_17_triggered();

    void on_actionEnglish_2_triggered();

    void on_action_22_triggered();

private:
    Ui::persian *ui;
    QBoxLayout *layout;
    QAbstractItemModel* tableModel;
    QDirModel *model;
    QDirModel *model2;
    QDirModel *model3;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    QFileSystemModel *filemodel2;
    QString path;
    QString path2;
    int iRows;
    int iRows2;
    QListWidgetItem *item;
    QListWidgetItem *item2;
};

#endif // PERSIAN_H








