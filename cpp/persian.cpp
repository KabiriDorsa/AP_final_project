#include "persian.h"
#include "ui_persian.h"
#include <fstream>
#include "qmessagebox.h"
#include <sstream>
#include <QTabWidget>
#include <QPlainTextEdit>
#include <QStatusBar>
#include <QLabel>
#include <QDirModel>
#include <QInputDialog>
#include <QWidget>
#include <QFileDialog>
#include <iostream>
#include "pset.h"
#include <QMainWindow>
#include <QTableView>
#include <QHeaderView>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QDialog>
#include "sync.h"


persian::persian(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::persian)
{

   ui->setupUi(this);
   ui->toolButton_68->setVisible(false);
   ui->toolButton_73->setVisible(false);
   ui->comboBox_27->setVisible(false);
   ui->pushButton_41->setVisible(false);
   ui->comboBox_28->setVisible(false);
   ui->pushButton_42->setVisible(false);


}


persian::~persian()
{
    delete ui;
}


void persian::on_pushButton_37_clicked()
{
    path =  QFileDialog::getExistingDirectory(this, tr("select a file"),
                                     tr(""),
                                     QFileDialog::ShowDirsOnly);

    ui->comboBox_25->addItem(path);
        }

void persian::on_pushButton_38_clicked()
{
    if(path != tr("") && path2 != tr("")){
    //table 1
    model = new QDirModel(this);
    model->setReadOnly(false);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->tableView_13->setModel(model);
    ui->tableView_13->resizeColumnToContents(0);
    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(path);
    ui->tableView_13->setModel(filemodel);
    ui->tableView_13->setRootIndex(filemodel->setRootPath(ui->comboBox_25->currentText()));

    QDir dir(path);
    iRows = dir.count();
    for(int i{1}; i <= iRows; i++){
        item = new QListWidgetItem(QString::number(i), ui->listWidget_13);
        item->setCheckState(Qt::Checked);
    }


    //table 2
    model2 = new QDirModel(this);
    model2->setReadOnly(false);
    model2->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->tableView_14->setModel(model2);
    ui->tableView_14->resizeColumnToContents(0);
    filemodel2 = new QFileSystemModel(this);
    filemodel2->setRootPath(path2);
    ui->tableView_14->setModel(filemodel2);
    ui->tableView_14->setRootIndex(filemodel2->setRootPath(ui->comboBox_26->currentText()));


    model3 = new QDirModel(this);
    model3->setReadOnly(false);
    ui->treeView_7->setModel(model3);
    QModelIndex index = model3->index(path);
    ui->treeView_7->expand(index);
    ui->treeView_7->scrollTo(index);
    ui->treeView_7->setCurrentIndex(index);
    ui->treeView_7->resizeColumnToContents(0);

    QDir dir2(path2);
    iRows2 = dir2.count();
    for(int i{1}; i <= iRows2; i++){
        item2 = new QListWidgetItem(QString::number(i), ui->listWidget_14);
        item2->setCheckState(Qt::Checked);
    }
    }
    QString text = QString("%1 فایل انتخاب شده").arg(iRows);
    ui->label->setText(text);
    QString text2 = QString("%1 فایل انتخاب شده").arg(iRows2);
    ui->label_2->setText(text2);

}



void persian::on_pushButton_39_clicked()
{
    path2 =  QFileDialog::getExistingDirectory(this, tr("select a file"),
                                     tr(""),
                                     QFileDialog::ShowDirsOnly);

    ui->comboBox_26->addItem(path2);
}

void persian::on_pushButton_40_clicked()
{
    if(path != tr("") && path2 != tr("")){
        filemodel2->setRootPath(path);
        ui->tableView_14->setModel(filemodel2);
        ui->tableView_14->setRootIndex(filemodel2->setRootPath(ui->comboBox_25->currentText()));
        QDir dir(path);
        iRows = dir.count();
        for(int i{1}; i <= iRows; i++){
            item = new QListWidgetItem(QString::number(i), ui->listWidget_14);
            item->setCheckState(Qt::Checked);
        }
        path = tr("");
        path2 = tr("");
    }
}


void persian::on_toolButton_67_clicked()
{
    if(path != tr("") && path2 != tr("")){
        while(ui->listWidget_13->count()>0 && ui->listWidget_14 > 0)
        {
          ui->listWidget_13->clear();//handle the item if you don't
                                  //have a pointer to it elsewhere
          ui->listWidget_14->clear();
        }
    QString temp;
    temp = path;
    path = path2;
    path2 = temp;
    filemodel2->setRootPath(path2);
    ui->tableView_14->setModel(filemodel2);
    ui->tableView_14->setRootIndex(filemodel2->setRootPath(path2));
    QDir dir2(path2);
    iRows2 = dir2.count();
    for(int i{1}; i <= iRows2; i++){
        item2 = new QListWidgetItem(QString::number(i), ui->listWidget_14);
        item2->setCheckState(Qt::Checked);

    }

    filemodel->setRootPath(path);
    ui->tableView_13->setModel(filemodel);
    ui->tableView_13->setRootIndex(filemodel->setRootPath(path));
    QDir dir(path);
    iRows = dir.count();
    for(int i{1}; i <= iRows; i++){
        item = new QListWidgetItem(QString::number(i), ui->listWidget_13);
        item->setCheckState(Qt::Checked);

    }

    }
    QString text = QString("%1 فایل انتخاب شده").arg(iRows);
    ui->label->setText(text);
    QString text2 = QString("%1 فایل انتخاب شده").arg(iRows);
    ui->label_2->setText(text2);
}

void persian::on_button_7_clicked()
{
    ui->toolButton_68->setVisible(true);
    ui->toolButton_73->setVisible(true);
    ui->comboBox_27->setVisible(true);
    ui->pushButton_41->setVisible(true);
    ui->comboBox_28->setVisible(true);
    ui->pushButton_42->setVisible(true);
}

void persian::on_toolButton_68_clicked()
{
    ui->toolButton_68->setVisible(false);
    ui->toolButton_73->setVisible(false);
    ui->comboBox_27->setVisible(false);
    ui->pushButton_41->setVisible(false);
    ui->comboBox_28->setVisible(false);
    ui->pushButton_42->setVisible(false);

}

void persian::on_toolButton_73_clicked()
{
    ui->toolButton_68->setVisible(false);
    ui->toolButton_73->setVisible(false);
    ui->comboBox_27->setVisible(false);
    ui->pushButton_41->setVisible(false);
    ui->comboBox_28->setVisible(false);
    ui->pushButton_42->setVisible(false);

}

void persian::on_pushButton_41_clicked()
{
    path =  QFileDialog::getExistingDirectory(this, tr("select a file"),
                                     tr(""),
                                     QFileDialog::ShowDirsOnly);

    ui->comboBox_27->addItem(path);
}

void persian::on_pushButton_42_clicked()
{
    path2 =  QFileDialog::getExistingDirectory(this, tr("select a file"),
                                     tr(""),
                                     QFileDialog::ShowDirsOnly);

    ui->comboBox_28->addItem(path2);
}


void persian::on_toolButton_69_clicked()
{
    pset *f = new pset(this); //or QMainWindow, or your custom class
    f->show();
}

void persian::on_toolButton_70_clicked()
{

    pset *f = new pset(this); //or QMainWindow, or your custom class
    f->show();
}

void persian::on_toolButton_71_clicked()
{
    pset *f = new pset(this); //or QMainWindow, or your custom class
    f->show();
}


void persian::on_listWidget_13_itemClicked(QListWidgetItem *item)
{
    int a = item->listWidget()->row(item);
        if(item->checkState() == Qt::Unchecked)
            ui->tableView_13->hideRow(a);
        if(item->checkState() == Qt::Checked)
            ui->tableView_13->showRow(a);
}

void persian::on_listWidget_14_itemClicked(QListWidgetItem *item)
{
    int b = item->listWidget()->row(item);
        if(item->checkState() == Qt::Unchecked)
            ui->tableView_14->hideRow(b);
        if(item->checkState() == Qt::Checked)
            ui->tableView_14->showRow(b);
}



void persian::on_action_3_triggered()
{
    std::ifstream iFile {QFileDialog::getOpenFileName(this, tr("select a file"),
                                     tr(""),
                                     tr("FreeFileSync (*.ffs_gui; *.ffs_batch);; Allfiles(*.*)")).toStdString()};
        if(!iFile){
            QMessageBox::critical(this, "خطا", "آیا مطمئن هستید؟");
            return;

        iFile.close();
        }
}

void persian::on_action_7_triggered()
{
    /* std::ofstream of{QFileDialog::getSaveFileName(this, tr("select a file"),
                                  tr(""),
                                  tr("FreeFileSync (*.ffs_gui; *.ffs_batch);; Allfiles(*.*)")).toStdString()};
     of << ui->tableView_13->toPlainText().toStdString();
     of.close();*/
}

void persian::on_action_10_triggered()
{
    qApp->exit();
}

void persian::on_action_11_triggered()
{
    if(path != tr("") && path2 != tr("")){
    //table 1
    model = new QDirModel(this);
    model->setReadOnly(false);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->tableView_13->setModel(model);
    ui->tableView_13->resizeColumnToContents(0);
    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(path);
    ui->tableView_13->setModel(filemodel);
    ui->tableView_13->setRootIndex(filemodel->setRootPath(ui->comboBox_25->currentText()));

    QDir dir(path);
    iRows = dir.count();
    for(int i{1}; i <= iRows; i++){
        item = new QListWidgetItem(QString::number(i), ui->listWidget_13);
        item->setCheckState(Qt::Checked);
    }


    //table 2
    model2 = new QDirModel(this);
    model2->setReadOnly(false);
    model2->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->tableView_14->setModel(model2);
    ui->tableView_14->resizeColumnToContents(0);
    filemodel2 = new QFileSystemModel(this);
    filemodel2->setRootPath(path2);
    ui->tableView_14->setModel(filemodel2);
    ui->tableView_14->setRootIndex(filemodel2->setRootPath(ui->comboBox_26->currentText()));

    QDir dir2(path2);
    iRows2 = dir2.count();
    for(int i{1}; i <= iRows2; i++){
        item2 = new QListWidgetItem(QString::number(i), ui->listWidget_14);
        item2->setCheckState(Qt::Checked);
    }

    model3 = new QDirModel(this);
    model3->setReadOnly(false);
    ui->treeView_7->setModel(model3);
    QModelIndex index = model3->index(path);
    ui->treeView_7->expand(index);
    ui->treeView_7->scrollTo(index);
    ui->treeView_7->setCurrentIndex(index);
    ui->treeView_7->resizeColumnToContents(0);


    }

}


void persian::on_action_13_triggered()
{
    pset *f = new pset(this); //or QMainWindow, or your custom class
    f->show();
}

void persian::on_action_14_triggered()
{
    pset *f = new pset(this); //or QMainWindow, or your custom class
    f->show();
}

void persian::on_action_15_triggered()
{
    pset *f = new pset(this); //or QMainWindow, or your custom class
    f->show();
}

void persian::on_action_17_triggered()
{
    if(path != tr("") && path2 != tr("")){
        filemodel2->setRootPath(path);
        ui->tableView_14->setModel(filemodel2);
        ui->tableView_14->setRootIndex(filemodel2->setRootPath(ui->comboBox_25->currentText()));
        QDir dir(path);
        iRows = dir.count();
        for(int i{1}; i <= iRows; i++){
            item = new QListWidgetItem(QString::number(i), ui->listWidget_14);
            item->setCheckState(Qt::Checked);
        }
        path = tr("");
        path2 = tr("");
    }
}

void persian::on_actionEnglish_2_triggered()
{
    this->hide();
    sync *p = new sync(this);
    p->show();
}

void persian::on_action_22_triggered()
{
    QString link = tr("https://freefilesync.org/manual.php?topic=freefilesync");
    QDesktopServices::openUrl(QUrl(link));
}
