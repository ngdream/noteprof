#include "mainwindow.h"

#include <QApplication>
#include<QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     a.setOrganizationName(QString("elodream"));
     QFile file(QString("style.css"));
     file.open(QFile::ReadOnly);
     QString stylesheet = QLatin1String(file.readAll());
     file.close();
     a.setStyleSheet(stylesheet);
    MainWindow w;
    w.show();
    return a.exec();
}
