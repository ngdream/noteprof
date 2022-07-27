#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");

    m_db.setDatabaseName("data.db");
    m_db.open();

    QSqlQuery query;
   query.prepare("INSERT INTO people (name) VALUES (:name)");
    query.bindValue(":name", "yo");
   bool  success = query.exec();
    qDebug()<<m_db.isValid();
    ui->setupUi(this);
    ui->widget->addAction(QString("acceuil"), QIcon(QString("home.png")));
    ui->widget->addAction(QString("editer"), QIcon(QString("edit.png")));
    connect(ui->actionA_propos, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actioncontacter_nous, &QAction::triggered, this, &MainWindow::contact);
    ui->widget->resize(100,500);
}

void MainWindow::about()
{
    AboutDialog dialog(this);
    dialog.exec();
}

void MainWindow::contact()
{
    contactdialog dialog(this);
    dialog.exec();
}
MainWindow::~MainWindow()
{
    delete ui;
}

