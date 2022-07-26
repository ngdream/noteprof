#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "teachertable.h"
#include "defs.h"
QSqlTableModel *Teachertable::model;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("database.sqlite");
    m_db.open();

    QSqlQuery query;

    query.exec("PRAGMA foreign_keys = ON;");
    // create miss table
    query.exec("create table absence  (mdata varchar(100),"
               "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
               "value int default 0,"
               "notationid integer REFERENCES notation(id) ON DELETE CASCADE )");

    // create la table
    query.exec("create table delay (mdata varchar(100),"
               "id integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
               " value int default 0,"
               "notationid integer REFERENCES notation(id) ON DELETE CASCADE); ");

    // create teacher table
    query.exec("create table teacher"
               "(name varchar(20)"
               ",first_name varchar(20),"
               "sex varchar(20), "
               "matricule varchar(10),photo_path varchar(200) ,"
               "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL );");

    // create notation document table

    query.exec("create table notation "
               "("
               "trimestre integer,"
               "classes varchar(200),"
               "disciplines varchar(100),"
               "annee varchar(100),"
               "slug varchar(100),"
               "id integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
               "teacherid integer REFERENCES teacher(ID) ON DELETE CASCADE,"

               // ponctuality
               ""
               " em int default 0,"

               // assuidity
               ""
               "pc boolean  default TRUE ,"
               "pr boolean default TRUE,"
               "ps boolean default  TRUE,"
               "pag boolean default TRUE,"
               "ace integer default 0,"
               "acc integer default 0,"

               // personal skills
               "ra boolean default true,"
               "ei boolean default true,"
               "re boolean default true,"
               "car boolean default true,"
               "tv boolean default true,"
               "r integer default 0 ,"

               "ma integer default 0,"
               "cl boolean default true,"

               // document clearing
               "modc boolean default true,"
               "chap boolean default true,"
               "ca boolean default true,"
               "ai boolean default true,"
               "stat boolean default true,"
               "rdate boolean default true,"
               "th boolean default true,"
               "planc boolean default true,"
               "updatec boolean default true,"
               "callreg integer default 0,"

               // confection
               "cs boolean default true,"
               "cc boolean default true,"
               "rds integer default 0,"
               "qs boolean default true,"
               "rdn integer default 0,"
               // quality
               " renh boolean default true,"
               "rpp boolean default true,"
               "fpc boolean default true,"
               "cp boolean default true,"
               "fp boolean default true,"
               "rch boolean default true,"
               "qc boolean default true,"
               // coordination
               "mvt integer default 1,"
               "mvc integer default 1,"
               "sp boolean default true,"
               "dfsp boolean default true,"
               "drce boolean default true,"
               "prc boolean default true,"
               "rpe boolean default true,"
               "dsp boolean default true,"
               "dch boolean default true,"
               "classed boolean default false,"
               "titulaire boolean default false);");

    m_home = new home;
    m_edit = new edition;

    m_home->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->k->addWidget(m_home);

    ui->sidebar2->hide();

    if (!m_db.isValid())
    {
        QMessageBox::critical(this, "erreur lors  de l'ouverture de la base de donnée", "impossible d'ouvrir la base de donnée, l'application va se fermer");
        this->close();
    }

    m_home_button = ui->widget->addAction(QString("acceuil"), QIcon(QString("home.png")));
    m_edit_button = ui->widget->addAction(QString("editer"), QIcon(QString("grey_edit.png")));

    connect(ui->actionA_propos, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actioncontacter_nous, &QAction::triggered, this, &MainWindow::contact);
    connect(ui->actionajouter, &QAction::triggered, this, &MainWindow::add);
    connect(ui->actionvoir, &QAction::triggered, this, &MainWindow::updateteacher);
    connect(ui->actionsupprimer, &QAction::triggered, this, &MainWindow::remove);
    connect(ui->actionsupprimer_tout,&QAction::triggered, this, &::MainWindow::removeall);

    connect(ui->widget, &SideBar::click, this, &MainWindow::switchtohome);
    connect(m_home, &home::sidebaractualised, this, &MainWindow::actualisedata);

    m_edit_button->setDisabled(true);

    m_home_button->setChecked(true);
    SideBar::mCheckedAction = m_home_button;
    ui->widget->resize(100, 500);
}

void MainWindow::actualisedata()
{
    m_edit->close();
    m_edit = new edition;
    m_edit->hide();
    ui->k->addWidget(m_edit);

    this->update();
    m_edit_button->setEnabled(true);
    m_edit_button->setIcon(QIcon(QString("edit.png")));
    ui->sidebar2->show();
    QSqlQuery query;
    query.prepare("SELECT photo_path,name,first_name,matricule FROM teacher WHERE ID =(:id)");
    query.bindValue(":id", Teachertable::selected);
    query.exec();
    query.next();
    QString nom = query.value(1).toString();
    QString prenom = query.value(2).toString();
    if (query.value(0).toString() != "")
    {
        QPixmap image(query.value(0).toString());
        ui->photoview->setPixmap(image.scaled(200, 200, Qt::KeepAspectRatio));
    }
    else
    {
        ui->photoview->setText("Photo non spécifée");
    }

    if (query.value(3).toString() != "")
        ui->matriculelabel->setText(query.value(3).toString());

    ui->nomlabel->setText(nom);
    ui->prenomlabel->setText(prenom);
    ui->statusBar->showMessage(prenom + " " + nom);
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

void MainWindow::updateteacher()
{
    editteacher dialog(this);
    dialog.exec();
}


void MainWindow::add()
{
    addteacher dialog(this);

    dialog.exec();
    Teachertable::model->select();
}

void MainWindow::remove()
{
    QSqlQuery query;
    query.prepare("delete from teacher where id=(:id);");
    query.bindValue(":id",Teachertable::selected);
    qDebug()<<Teachertable::selected;
    query.exec();
    Teachertable::model->select();

    //actualise data
     edition::model->fetchMore();
     QSqlQuery q = edition::model->query();
     q.exec();
     edition::model->setQuery(q);
}

void MainWindow::removeall()
{
    QSqlQuery query;
    query.prepare("DELETE FROM teacher;");
    query.exec();
    if (!query.exec()) {
        qDebug()<<query.lastError();
        return;
    }
    Teachertable::model->select();
    qDebug()<<"all data removed";

    //actualise data
     edition::model->fetchMore();
     QSqlQuery q = edition::model->query();
     q.exec();
     edition::model->setQuery(q);
}
void MainWindow::switchtohome()
{
    if (m_home_button->isChecked())
    {
        m_home->show();
        m_edit->hide();
    }
    else if (m_edit_button->isChecked())
    {

        m_edit->show();
        m_home->hide();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
