#include "home.h"
#include "ui_home.h"
#include <QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QSqlTableModel>


void initializeModel(QSqlTableModel *model)
{
    model->setTable("teacher");
    model->select();


//! [3]
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("first name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("sex"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id"));
//! [3]

}

home::home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    QSqlTableModel *model=new  QSqlTableModel() ;
    initializeModel(model);
    ui->tableteacher->horizontalHeader()->setStretchLastSection(true);
   ui->tableteacher->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableteacher->setModel(model);


}

home::~home()
{
    delete ui;
}
