#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("database.sqlite");
    m_db.open();

    QSqlQuery query;
    query.exec("create table teacher(name varchar(20),first_name varchar(20),sex varchar(20),id int primary key)");
    bool  success = query.exec();
    m_home=new home;

   ui->k->addWidget(m_home);

m_home->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   m_home->show();


    qDebug()<<m_db.isValid();

    ui->widget->addAction(QString("acceuil"), QIcon(QString("home.png")));
    ui->widget->addAction(QString("editer"), QIcon(QString("edit.png")));
    connect(ui->actionA_propos, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actioncontacter_nous, &QAction::triggered, this, &MainWindow::contact);
    connect(ui->actionajouter, &QAction::triggered, this, &MainWindow::add);
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

void MainWindow::add()
{
    addteacher dialog(this);

    dialog.exec();
    m_home->close();
    m_home=new home();
    ui->k->addWidget(m_home);
}


void MainWindow::remove()
{
    contactdialog dialog(this);
    dialog.exec();
}



MainWindow::~MainWindow()
{
    delete ui;
}

