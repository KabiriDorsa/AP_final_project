#include "pset.h"
#include "ui_pset.h"
#include <QComboBox>
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>

pset::pset(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pset)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    ui->checkBox_20->setCheckState(Qt::Unchecked);
    ui->toolButton_40->hide();
    ui->toolButton_30->hide();
    ui->toolButton_20->hide();
    ui->toolButton_50->hide();
    ui->toolButton_60->hide();
    ui->toolButton_70->hide();
    ui->textBrowser_60->hide();
    ui->textBrowser_70->hide();
    ui->textBrowser_80->hide();
    ui->textBrowser_90->hide();
    ui->checkBox_100->setEnabled(false);

    ui->textEdit_30->show();
    ui->label_50->show();
    ui->toolButton_90->hide();
    ui->toolButton_11->hide();
    ui->textBrowser_90->hide();
    ui->textBrowser_11->hide();
    ui->comboBox_40->hide();
    ui->pushButton_120->hide();
    ui->pushButton_160->hide();
    ui->label->hide();


 }

pset::~pset()
{
    delete ui;
}


void pset::on_comboBox_30_currentIndexChanged(int index)
{
    if(index > 0){
    ui->label_60->setEnabled(true);
    ui->spinBox_100->setEnabled(true);
    }
}

void pset::on_comboBox_100_currentIndexChanged(int index)
{
    if(index > 0)
    {
    ui->label_60->setEnabled(true);
    ui->spinBox_30->setEnabled(true);
}
}

void pset::on_comboBox_20_currentIndexChanged(int index)
{
    if(index > 0){
    ui->label_70->setEnabled(true);
    ui->spinBox_20->setEnabled(true);
}
}

void pset::on_pushButton_100_clicked()
{
    ui->textBrowser_30->show();
    ui->textBrowser_40->hide();
    ui->textBrowser_50->hide();
    ui->toolButton_100->show();
    ui->toolButton_20->hide();
    ui->toolButton_30->hide();
}

void pset::on_pushButton_20_clicked()
{
    ui->textBrowser_30->hide();
    ui->textBrowser_40->show();
    ui->textBrowser_50->hide();
    ui->toolButton_100->hide();
    ui->toolButton_20->show();
    ui->toolButton_30->hide();
}



void pset::on_pushButton_30_clicked()
{
    ui->textBrowser_30->hide();
    ui->textBrowser_40->hide();
    ui->textBrowser_50->show();
    ui->toolButton_100->hide();
    ui->toolButton_20->hide();
    ui->toolButton_30->show();
    ui->checkBox_100->hide();
}

void pset::on_buttonBox_rejected()
{
    QWidget::close();
}

//void pset::setValue(int a){
    //ui->tabWidget->setCurrentIndex(a);
//}

//void pset::setUpPage(){
    //QObject::connect(sender(), SIGNAL(sendSignal(int)),this , SLOT(setValue(int)));

//}



void pset::on_checkBox_20_clicked()
{

    if(ui->checkBox_20->checkState() == Qt::Unchecked){
    ui->radioButton_100->setDisabled(true);
    ui->radioButton_20->setDisabled(true);
    }
    if(ui->checkBox_20->checkState() == Qt::Checked){
    ui->radioButton_100->setEnabled(true);
    ui->radioButton_20->setEnabled(true);
    }
}


void pset::on_pushButton_130_clicked()
{
    QString link = tr("https://freefilesync.org/manual.php?topic=comparison-settings");
    QDesktopServices::openUrl(QUrl(link));
}

void pset::on_pushButton_140_clicked()
{
    QString link = tr("https://freefilesync.org/manual.php?topic=daylight-saving-time");
    QDesktopServices::openUrl(QUrl(link));
}

void pset::on_pushButton_40_clicked()
{
    ui->label_30->show();
    ui->textBrowser_100->show();
    ui->toolButton_40->hide();
    ui->toolButton_50->hide();
    ui->toolButton_60->hide();
    ui->toolButton_70->hide();
    ui->textBrowser_60->hide();
    ui->textBrowser_70->hide();
    ui->textBrowser_80->hide();
    ui->textBrowser_90->hide();
    ui->checkBox_100->setEnabled(false);
    ui->checkBox_100->setCheckState(Qt::Checked);
}

void pset::on_pushButton_150_clicked()
{
    QString link = tr("https://freefilesync.org/manual.php?topic=synchronization-settings");
    QDesktopServices::openUrl(QUrl(link));
}

void pset::on_pushButton_50_clicked()
{
    ui->textBrowser_60->show();
    ui->toolButton_40->show();
    ui->toolButton_50->show();
    ui->toolButton_60->show();
    ui->checkBox_100->setEnabled(true);
    ui->checkBox_100->setCheckState(Qt::Checked);
    ui->label_30->hide();
    ui->textBrowser_100->hide();
    ui->toolButton_70->hide();
    ui->textBrowser_70->hide();
    ui->textBrowser_80->hide();
    ui->textBrowser_90->hide();



}

void pset::on_pushButton_60_clicked()
{
    ui->label_30->hide();
    ui->textBrowser_100->hide();
    ui->toolButton_40->show();
    ui->toolButton_50->show();
    ui->toolButton_60->hide();
    ui->toolButton_70->show();
    ui->textBrowser_60->hide();
    ui->textBrowser_70->show();
    ui->textBrowser_80->hide();
    ui->textBrowser_90->hide();
    ui->checkBox_100->setEnabled(true);
    ui->checkBox_100->setCheckState(Qt::Checked);
}

void pset::on_pushButton_70_clicked()
{
    ui->textBrowser_60->hide();
    ui->toolButton_40->show();
    ui->toolButton_50->show();
    ui->toolButton_60->show();
    ui->checkBox_100->setEnabled(true);
    ui->checkBox_100->setCheckState(Qt::Unchecked);
    ui->label_30->hide();
    ui->textBrowser_100->hide();
    ui->toolButton_70->hide();
    ui->textBrowser_70->hide();
    ui->textBrowser_80->show();
    ui->textBrowser_90->hide();
}

void pset::on_pushButton_80_clicked()
{
    ui->textEdit_30->show();
    ui->label_50->show();
    ui->toolButton_90->hide();
    ui->toolButton_11->hide();
    ui->textBrowser_90->hide();
    ui->textBrowser_11->hide();
    ui->comboBox_40->hide();
    ui->pushButton_120->hide();
    ui->pushButton_160->hide();
}

void pset::on_pushButton_90_clicked()
{
    ui->textEdit_30->hide();
    ui->label_50->hide();
    ui->toolButton_90->show();
    ui->toolButton_11->hide();
    ui->textBrowser_90->show();
    ui->textBrowser_11->hide();
    ui->comboBox_40->hide();
    ui->pushButton_120->hide();
    ui->pushButton_160->hide();
}

void pset::on_pushButton_11_clicked()
{
    ui->textEdit_30->hide();
    ui->label_50->hide();
    ui->toolButton_90->hide();
    ui->toolButton_11->show();
    ui->textBrowser_90->hide();
    ui->textBrowser_11->show();
    ui->comboBox_40->show();
    ui->pushButton_120->show();
    ui->pushButton_160->show();
}

void pset::on_pushButton_160_clicked()
{
    QString link = tr("https://freefilesync.org/manual.php?topic=versioning");
    QDesktopServices::openUrl(QUrl(link));
}

void pset::on_pushButton_120_clicked()
{
    QString path;
    path =  QFileDialog::getExistingDirectory(this, tr("select a file"),
                                     tr(""),
                                     QFileDialog::ShowDirsOnly);

    ui->comboBox_40->addItem(path);
}


void pset::on_buttonBox_accepted()
{
    QWidget::close();
}
