#include "sync.h"
#include "ui_sync.h"
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
#include "set.h"
#include <QMainWindow>
#include <QTableView>
#include <QHeaderView>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QDialog>
#include "persian.h"
#include <QProcess>


sync::sync(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sync)
{

   ui->setupUi(this);
   ui->toolButton_12->setVisible(false);
   ui->toolButton_9->setVisible(false);
   ui->comboBox_3->setVisible(false);
   ui->pushButton_5->setVisible(false);
   ui->comboBox_4->setVisible(false);
   ui->pushButton_6->setVisible(false);


}


sync::~sync()
{
    delete ui;
}

void sync::on_actionOpen_triggered()
{
    std::ifstream iFile {QFileDialog::getOpenFileName(this, tr("select a file"),
                                     tr(""),
                                     tr("FreeFileSync (*.ffs_gui; *.ffs_batch);; Allfiles(*.*)")).toStdString()};
        if(!iFile){
            QMessageBox::critical(this, "Error", "Are you Sure?");
            return;

        iFile.close();

}
}


void sync::on_actionSave_triggered()
{
   /* std::ofstream of{QFileDialog::getSaveFileName(this, tr("select a file"),
                                 tr(""),
                                 tr("FreeFileSync (*.ffs_gui; *.ffs_batch);; Allfiles(*.*)")).toStdString()};
    of << ui->tableView->toPlainText().toStdString();
    of.close();*/
}

void sync::on_actionExit_triggered()
{
    qApp->exit();
}

void sync::on_pushButton_3_clicked()
{
    path =  QFileDialog::getExistingDirectory(this, tr("select a file"),
                                     tr(""),
                                     QFileDialog::ShowDirsOnly);

    ui->comboBox->addItem(path);
        }

void sync::on_pushButton_clicked()
{
    if(path != tr("") && path2 != tr("")){
    //table 1
    model = new QDirModel(this);
    model->setReadOnly(false);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnToContents(0);
    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(path);
    ui->tableView->setModel(filemodel);
    ui->tableView->setRootIndex(filemodel->setRootPath(ui->comboBox->currentText()));

    QDir dir(path);
    iRows = dir.count();
    for(int i{1}; i <= iRows; i++){
        item = new QListWidgetItem(QString::number(i), ui->listWidget);
        item->setCheckState(Qt::Checked);
    }


    //table 2
    model2 = new QDirModel(this);
    model2->setReadOnly(false);
    model2->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->tableView_2->setModel(model2);
    ui->tableView_2->resizeColumnToContents(0);
    filemodel2 = new QFileSystemModel(this);
    filemodel2->setRootPath(path2);
    ui->tableView_2->setModel(filemodel2);
    ui->tableView_2->setRootIndex(filemodel2->setRootPath(ui->comboBox_2->currentText()));


    model3 = new QDirModel(this);
    //model3->setRootPath(QDir::currentPath());
    model3->setReadOnly(false);
//    model3->setSorting(QDir::IgnoreCase | QDir::Name);
    ui->treeView->setModel(model3);
    QModelIndex index = model3->index(path);
    //
    QModelIndex index2 = model3->index(path2);
    //
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    //
    ui->treeView->expand(index2);
    ui->treeView->scrollTo(index2);
    ui->treeView->setCurrentIndex(index2);
    //
    ui->treeView->resizeColumnToContents(0);

    QDir dir2(path2);
    iRows2 = dir2.count();
    for(int i{1}; i <= iRows2; i++){
        item2 = new QListWidgetItem(QString::number(i), ui->listWidget_2);
        item2->setCheckState(Qt::Checked);
    }

    }

    QString text = QString("%1 file(s) selected").arg(iRows);
    ui->label_5->setText(text);
    QString text2 = QString("%1 file(s) selected").arg(iRows2);
    ui->label_6->setText(text2);



    //Runing python script
//    QString path = "E:/AUT/semester 8/AP/project/python/main.py";
    //QString  command("python");
    //QStringList params = QStringList() << "main.py";
    //QString path = QCoreApplication::applicationDirPath();
//    QString  command("python");
//    QStringList params = QStringList() << "main.py";

//    QProcess *process = new QProcess(this);
//    process->start(path);
    //process->waitForFinished();
    //process->close();

}



void sync::on_pushButton_4_clicked()
{
    path2 =  QFileDialog::getExistingDirectory(this, tr("select a file"),
                                     tr(""),
                                     QFileDialog::ShowDirsOnly);

    ui->comboBox_2->addItem(path2);
}

void sync::on_pushButton_2_clicked()
{
    if(path != tr("") && path2 != tr("")){
        filemodel2->setRootPath(path);
        ui->tableView_2->setModel(filemodel2);
        ui->tableView_2->setRootIndex(filemodel2->setRootPath(ui->comboBox->currentText()));
        QDir dir(path);
        iRows = dir.count();
        for(int i{1}; i <= iRows; i++){
            item = new QListWidgetItem(QString::number(i), ui->listWidget_2);
            item->setCheckState(Qt::Checked);
        }
        path = tr("");
        path2 = tr("");
    }
}


void sync::on_toolButton_10_clicked()
{
    if(path != tr("") && path2 != tr("")){
        while(ui->listWidget->count()>0 && ui->listWidget_2 > 0)
        {
          ui->listWidget->clear();//handle the item if you don't
                                  //have a pointer to it elsewhere
          ui->listWidget_2->clear();
        }
    QString temp;
    temp = path;
    path = path2;
    path2 = temp;
    filemodel2->setRootPath(path2);
    ui->tableView_2->setModel(filemodel2);
    ui->tableView_2->setRootIndex(filemodel2->setRootPath(path2));
    QDir dir2(path2);
    iRows2 = dir2.count();
    for(int i{1}; i <= iRows2; i++){
        item2 = new QListWidgetItem(QString::number(i), ui->listWidget_2);
        item2->setCheckState(Qt::Checked);

    }

    filemodel->setRootPath(path);
    ui->tableView->setModel(filemodel);
    ui->tableView->setRootIndex(filemodel->setRootPath(path));
    QDir dir(path);
    iRows = dir.count();
    for(int i{1}; i <= iRows; i++){
        item = new QListWidgetItem(QString::number(i), ui->listWidget);
        item->setCheckState(Qt::Checked);

    }

    }
    QString text = QString("%1 file(s) selected").arg(iRows);
    ui->label_5->setText(text);
    QString text2 = QString("%1 file(s) selected").arg(iRows2);
    ui->label_6->setText(text2);
}

void sync::on_button_clicked()
{
    ui->toolButton_12->setVisible(true);
    ui->toolButton_9->setVisible(true);
    ui->comboBox_3->setVisible(true);
    ui->pushButton_5->setVisible(true);
    ui->comboBox_4->setVisible(true);
    ui->pushButton_6->setVisible(true);
}

void sync::on_toolButton_12_clicked()
{
    ui->toolButton_12->setVisible(false);
    ui->toolButton_9->setVisible(false);
    ui->comboBox_3->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->comboBox_4->setVisible(false);
    ui->pushButton_6->setVisible(false);

}

void sync::on_toolButton_9_clicked()
{
    ui->toolButton_12->setVisible(false);
    ui->toolButton_9->setVisible(false);
    ui->comboBox_3->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->comboBox_4->setVisible(false);
    ui->pushButton_6->setVisible(false);

}

void sync::on_pushButton_5_clicked()
{
    path =  QFileDialog::getExistingDirectory(this, tr("select a file"),
                                     tr(""),
                                     QFileDialog::ShowDirsOnly);

    ui->comboBox_3->addItem(path);
}

void sync::on_pushButton_6_clicked()
{
    path2 =  QFileDialog::getExistingDirectory(this, tr("select a file"),
                                     tr(""),
                                     QFileDialog::ShowDirsOnly);

    ui->comboBox_4->addItem(path2);
}


void sync::on_toolButton_7_clicked()
{
    Set *f = new Set(this); //or QMainWindow, or your custom class
    f->show();
}

void sync::on_toolButton_8_clicked()
{
    Set *f = new Set(this); //or QMainWindow, or your custom class
    f->show();
}

void sync::on_toolButton_6_clicked()
{
    Set *f = new Set(this); //or QMainWindow, or your custom class
    f->show();
}


void sync::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int a = item->listWidget()->row(item);
        if(item->checkState() == Qt::Unchecked)
            ui->tableView->hideRow(a);
        if(item->checkState() == Qt::Checked)
            ui->tableView->showRow(a);
}

void sync::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    int b = item->listWidget()->row(item);
        if(item->checkState() == Qt::Unchecked)
            ui->tableView_2->hideRow(b);
        if(item->checkState() == Qt::Checked)
            ui->tableView_2->showRow(b);
}


void sync::on_actionStart_comparison_2_triggered()
{
    if(path != tr("") && path2 != tr("")){
    //table 1
    model = new QDirModel(this);
    model->setReadOnly(false);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnToContents(0);
    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(path);
    ui->tableView->setModel(filemodel);
    ui->tableView->setRootIndex(filemodel->setRootPath(ui->comboBox->currentText()));

    QDir dir(path);
    iRows = dir.count();
    for(int i{1}; i <= iRows; i++){
        item = new QListWidgetItem(QString::number(i), ui->listWidget);
        item->setCheckState(Qt::Checked);
    }


    //table 2
    model2 = new QDirModel(this);
    model2->setReadOnly(false);
    model2->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    ui->tableView_2->setModel(model2);
    ui->tableView_2->resizeColumnToContents(0);
    filemodel2 = new QFileSystemModel(this);
    filemodel2->setRootPath(path2);
    ui->tableView_2->setModel(filemodel2);
    ui->tableView_2->setRootIndex(filemodel2->setRootPath(ui->comboBox_2->currentText()));


    model3 = new QDirModel(this);
    model3->setReadOnly(false);
    //model3->setRootPath(QDir::currentPath());
    ui->treeView->setModel(model3);
    QModelIndex index = model3->index(path);
    //
    QModelIndex index2 = model3->index(path2);
    //
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    //
    ui->treeView->expand(index2);
    ui->treeView->scrollTo(index2);
    ui->treeView->setCurrentIndex(index2);
    //
    ui->treeView->resizeColumnToContents(0);

    QDir dir2(path2);
    iRows2 = dir2.count();
    for(int i{1}; i <= iRows2; i++){
        item2 = new QListWidgetItem(QString::number(i), ui->listWidget_2);
        item2->setCheckState(Qt::Checked);
    }
    }

}

void sync::on_actionComparison_settings_2_triggered()
{
    Set *f = new Set(this); //or QMainWindow, or your custom class
    f->show();


}

void sync::on_actionView_help_triggered()
{
    QString link = tr("https://freefilesync.org/manual.php?topic=freefilesync");
    QDesktopServices::openUrl(QUrl(link));
}

void sync::on_actionStart_synchronization_triggered()
{
    if(path != tr("") && path2 != tr("")){
        filemodel2->setRootPath(path);
        ui->tableView_2->setModel(filemodel2);
        ui->tableView_2->setRootIndex(filemodel2->setRootPath(ui->comboBox->currentText()));
        QDir dir(path);
        iRows = dir.count();
        for(int i{1}; i <= iRows; i++){
            item = new QListWidgetItem(QString::number(i), ui->listWidget_2);
            item->setCheckState(Qt::Checked);
        }
        path = tr("");
        path2 = tr("");
    }
}

void sync::on_action_triggered()
{
    this->hide();
    persian *p = new persian(this);
    p->show();

}

void sync::on_actionFilter_settings_triggered()
{
    Set *f = new Set(this); //or QMainWindow, or your custom class
    f->show();
}



void sync::on_actionSynchronization_settings_triggered()
{
    Set *f = new Set(this); //or QMainWindow, or your custom class
    f->show();
}
