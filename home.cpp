#include "home.h"
#include "ui_home.h"
#include <QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QSqlTableModel>

// create the display of our teacher table
void initializeModel(QSqlTableModel *model)
{
    model->setTable("teacher");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("sex"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));

   model->removeColumn(4); //remove id and photo_ath from data view



}

//create teacher table

home::home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    Teachertable::model=new  QSqlTableModel() ;

    //make  a model for our teacher table
    initializeModel(Teachertable::model);
    ui->tableteacher->setModel(Teachertable:: model);

    ui->tableteacher->horizontalHeader()->setStretchLastSection(true);
    ui->tableteacher->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableteacher->verticalHeader()->hide();

    //other setting of teacher view
    ui->tableteacher->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableteacher->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableteacher->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableteacher->setColumnHidden(4,true);
    connect(ui->tableteacher,&Teachertable::selectionchanged,this,&home::selectionchanged);

}

void home::selectionchanged()
{
    //emit signal for sidebar actualisation
    emit sidebaractualised();
}
home::~home()
{
    delete ui;
}
