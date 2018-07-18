#ifndef SYNC_H
#define SYNC_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDirModel>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include "set.h"
#include<string>
#include <iostream>
#include <QFileSystemModel>
#include <QVBoxLayout>
#include <QAbstractItemModel>
#include <QListWidgetItem>

namespace Ui {
class sync;
}

class sync : public QMainWindow
{
    Q_OBJECT


public:
    explicit sync(QWidget *parent = 0);

    ~sync();

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void on_toolButton_10_clicked();
    void on_button_clicked();
    void on_toolButton_12_clicked();
    void on_toolButton_9_clicked();
    void on_pushButton_5_clicked();
    void on_toolButton_6_clicked();
    void on_toolButton_7_clicked();
    void on_toolButton_8_clicked();
    void on_pushButton_6_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_2_itemClicked(QListWidgetItem *item);

    //void on_calendarWidget_clicked(const QDate &date);

    void on_actionStart_comparison_2_triggered();

    void on_actionComparison_settings_2_triggered();

    void on_actionView_help_triggered();

    void on_actionStart_synchronization_triggered();

    void on_action_triggered();

    void on_actionFilter_settings_triggered();

    void on_actionSynchronization_settings_triggered();

private:

    QBoxLayout *layout;
    Ui::sync *ui;
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

#endif // SYNC_H
