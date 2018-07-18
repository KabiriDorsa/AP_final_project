#include "set.h"
#include "ui_set.h"
#include <QComboBox>
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>

Set::Set(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Set)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    ui->toolButton_4->hide();
    ui->toolButton_2->hide();
    ui->toolButton_3->hide();
    ui->toolButton_5->hide();
    ui->toolButton_6->hide();
    ui->toolButton_7->hide();
    ui->textBrowser_6->hide();
    ui->textBrowser_7->hide();
    ui->textBrowser_8->hide();
    ui->textBrowser_9->hide();
    ui->checkBox->setEnabled(false);

    ui->textEdit_3->show();
    ui->label_5->show();
    ui->toolButton_9->hide();
    ui->toolButton_10->hide();
    ui->textBrowser_9->hide();
    ui->textBrowser_10->hide();
    ui->comboBox_4->hide();
    ui->pushButton_12->hide();
    ui->pushButton_16->hide();
    ui->label_8->hide();



 }

Set::~Set()
{
    delete ui;
}


void Set::on_comboBox_3_currentIndexChanged(int index)
{
    if(index > 0){
    ui->label_6->setEnabled(true);
    ui->spinBox->setEnabled(true);
    }
}

void Set::on_comboBox_currentIndexChanged(int index)
{
    if(index > 0)
    {
    ui->label_6->setEnabled(true);
    ui->spinBox_3->setEnabled(true);
}
}

void Set::on_comboBox_2_currentIndexChanged(int index)
{
    if(index > 0){
    ui->label_7->setEnabled(true);
    ui->spinBox_2->setEnabled(true);
}
}

void Set::on_pushButton_clicked()
{
    ui->textBrowser_3->show();
    ui->textBrowser_4->hide();
    ui->textBrowser_5->hide();
    ui->toolButton->show();
    ui->toolButton_2->hide();
    ui->toolButton_3->hide();
}

void Set::on_pushButton_2_clicked()
{
    ui->textBrowser_3->hide();
    ui->textBrowser_4->show();
    ui->textBrowser_5->hide();
    ui->toolButton->hide();
    ui->toolButton_2->show();
    ui->toolButton_3->hide();
}



void Set::on_pushButton_3_clicked()
{
    ui->textBrowser_3->hide();
    ui->textBrowser_4->hide();
    ui->textBrowser_5->show();
    ui->toolButton->hide();
    ui->toolButton_2->hide();
    ui->toolButton_3->show();
    ui->checkBox->hide();
}

void Set::on_buttonBox_rejected()
{
    QWidget::close();
}

/*void Set::setValue(int a){
    ui->tabWidget->setCurrentIndex(a);
}

void Set::setUpPage(){
    QObject::connect(sender(), SIGNAL(sendSignal(int)),this , SLOT(setValue(int)));

}*/

void Set::on_checkBox_2_clicked()
{

    if(ui->checkBox_2->checkState() == Qt::Unchecked){
    ui->radioButton->setDisabled(true);
    ui->radioButton_2->setDisabled(true);
    }
    if(ui->checkBox_2->checkState() == Qt::Checked){
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    }
}


void Set::on_pushButton_13_clicked()
{
    QString link = tr("https://freefilesync.org/manual.php?topic=comparison-settings");
    QDesktopServices::openUrl(QUrl(link));
}

void Set::on_pushButton_14_clicked()
{
    QString link = tr("https://freefilesync.org/manual.php?topic=daylight-saving-time");
    QDesktopServices::openUrl(QUrl(link));
}

void Set::on_pushButton_4_clicked()
{
    ui->label_3->show();
    ui->textBrowser->show();
    ui->toolButton_4->hide();
    ui->toolButton_5->hide();
    ui->toolButton_6->hide();
    ui->toolButton_7->hide();
    ui->textBrowser_6->hide();
    ui->textBrowser_7->hide();
    ui->textBrowser_8->hide();
    ui->textBrowser_9->hide();
    ui->checkBox->setEnabled(false);
    ui->checkBox->setCheckState(Qt::Checked);
}

void Set::on_pushButton_15_clicked()
{
    QString link = tr("https://freefilesync.org/manual.php?topic=synchronization-settings");
    QDesktopServices::openUrl(QUrl(link));
}

void Set::on_pushButton_5_clicked()
{
    ui->textBrowser_6->show();
    ui->toolButton_4->show();
    ui->toolButton_5->show();
    ui->toolButton_6->show();
    ui->checkBox->setEnabled(true);
    ui->checkBox->setCheckState(Qt::Checked);
    ui->label_3->hide();
    ui->textBrowser->hide();
    ui->toolButton_7->hide();
    ui->textBrowser_7->hide();
    ui->textBrowser_8->hide();
    ui->textBrowser_9->hide();



}

void Set::on_pushButton_6_clicked()
{
    ui->label_3->hide();
    ui->textBrowser->hide();
    ui->toolButton_4->show();
    ui->toolButton_5->show();
    ui->toolButton_6->hide();
    ui->toolButton_7->show();
    ui->textBrowser_6->hide();
    ui->textBrowser_7->show();
    ui->textBrowser_8->hide();
    ui->textBrowser_9->hide();
    ui->checkBox->setEnabled(true);
    ui->checkBox->setCheckState(Qt::Checked);
}

void Set::on_pushButton_7_clicked()
{
    ui->textBrowser_6->hide();
    ui->toolButton_4->show();
    ui->toolButton_5->show();
    ui->toolButton_6->show();
    ui->checkBox->setEnabled(true);
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->label_3->hide();
    ui->textBrowser->hide();
    ui->toolButton_7->hide();
    ui->textBrowser_7->hide();
    ui->textBrowser_8->show();
    ui->textBrowser_9->hide();
}

void Set::on_pushButton_8_clicked()
{
    ui->textEdit_3->show();
    ui->label_5->show();
    ui->toolButton_9->hide();
    ui->toolButton_10->hide();
    ui->textBrowser_9->hide();
    ui->textBrowser_10->hide();
    ui->comboBox_4->hide();
    ui->pushButton_12->hide();
    ui->pushButton_16->hide();
}

void Set::on_pushButton_9_clicked()
{
    ui->textEdit_3->hide();
    ui->label_5->hide();
    ui->toolButton_9->show();
    ui->toolButton_10->hide();
    ui->textBrowser_9->show();
    ui->textBrowser_10->hide();
    ui->comboBox_4->hide();
    ui->pushButton_12->hide();
    ui->pushButton_16->hide();
}

void Set::on_pushButton_10_clicked()
{
    ui->textEdit_3->hide();
    ui->label_5->hide();
    ui->toolButton_9->hide();
    ui->toolButton_10->show();
    ui->textBrowser_9->hide();
    ui->textBrowser_10->show();
    ui->comboBox_4->show();
    ui->pushButton_12->show();
    ui->pushButton_16->show();
}

void Set::on_pushButton_16_clicked()
{
    QString link = tr("https://freefilesync.org/manual.php?topic=versioning");
    QDesktopServices::openUrl(QUrl(link));
}

void Set::on_pushButton_12_clicked()
{
    QString path;
    path =  QFileDialog::getExistingDirectory(this, tr("select a file"),
                                     tr(""),
                                     QFileDialog::ShowDirsOnly);

    ui->comboBox_4->addItem(path);
}

void Set::on_buttonBox_accepted()
{
    QWidget::close();
}
