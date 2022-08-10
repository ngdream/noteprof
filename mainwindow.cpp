#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "teachertable.h"
#include "defs.h"
QSqlTableModel * Teachertable::model;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("database.sqlite");
    m_db.open();

    QSqlQuery query;
    query.exec("create table teacher(name varchar(20),first_name varchar(20),sex varchar(20), matricule varchar(10) ,photo_path varchar(200) ,ID    integer PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE )");
    bool  success = query.exec();


    m_home=new home;

    m_home->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   ui->k->addWidget(m_home);


    ui->sidebar2->hide();

    if(!m_db.isValid())
    {
        QMessageBox::critical(this,"erreur lors  de l'ouverture de la base de donnée","impossible d'ouvrir la base de donnée, l'application va se fermer");
        this->close();
    }


    m_home_button=ui->widget->addAction(QString("acceuil"), QIcon(QString("home.png")));
    m_edit_button=ui->widget->addAction(QString("editer"), QIcon(QString("grey_edit.png")));

    connect(ui->actionA_propos, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actioncontacter_nous, &QAction::triggered, this, &MainWindow::contact);
    connect(ui->actionajouter, &QAction::triggered, this, &MainWindow::add);


    connect(ui->widget, &SideBar::click, this,&MainWindow::switchtohome);
    connect(m_home,&home::sidebaractualised, this,&MainWindow::actualisedata);

    m_edit_button->setDisabled(true);


    m_home_button->setChecked(true);
    SideBar::mCheckedAction=m_home_button;
    ui->widget->resize(100,500);

}


void MainWindow::actualisedata()
{
    m_edit->close();
     m_edit=new edition;
    m_edit->hide();
    ui->k->addWidget(m_edit);

    this->update();
    m_edit_button->setEnabled(true);
    m_edit_button->setIcon(QIcon(QString("edit.png")));
    ui->sidebar2->show();
    QSqlQuery query;
    query.prepare("SELECT photo_path FROM teacher WHERE ID =(:id)");
    query.bindValue(":id",Teachertable::selected);
    query.exec();
    query.next();
    qDebug()<<query.value(0).toString()<<Teachertable::selected;
QPixmap image(query.value(0).toString());
;
ui->photoview->setPixmap(image.scaled(200,200,Qt::KeepAspectRatio));


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
   /* m_home->close();
    m_home=new home();
    ui->k->addWidget(m_home);*/
    Teachertable::model->select();
}


void MainWindow::remove()
{
    contactdialog dialog(this);
    dialog.exec();
}

void MainWindow::switchtohome()
{
if(m_home_button->isChecked())
{
      m_home->show();
      m_edit->hide();
}
else if(m_edit_button->isChecked())
{

    m_edit->show();
    m_home->hide();
}

}



MainWindow::~MainWindow()
{
    delete ui;
}

