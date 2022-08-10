/*
made by elodream copyright 2022  for the
bilingual catholic college francois xavier mvogt
*/


#include "mainwindow.h"

#include <QApplication>
#include<QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName(QString("elodream"));

    // open our stylesheet ("style.css")
    QFile file(QString("style.css"));
    file.open(QFile::ReadOnly);
    // set our aplication style
    if(file.isOpen())
    {
        QString stylesheet = QLatin1String(file.readAll());
        file.close();
        a.setStyleSheet(stylesheet);
    }

    MainWindow w;
    w.show(); // show our application
    return a.exec();
}
