#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->addAction(QString("acceuil"), QIcon(QString("home.png")));
    ui->widget->addAction(QString("editer"), QIcon(QString("edit.png")));
    ui->widget->resize(100,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

