#include "sync.h"
#include <QApplication>
#include <QtGui>
#include <QWidget>
#include "set.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setWindowIcon(QIcon{"myappico.ico"});

    sync w;
    w.show();

    return a.exec();

}
