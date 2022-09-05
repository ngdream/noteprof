#include "absence.h"
#include "ui_absence.h"
#include"edition.h"
QSqlQueryModel *absence::model;
absence::absence(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::absence)
{

    ui->setupUi(this);
    absence::model= new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT mdata,value  FROM absence WHERE notationid =(:id)");
    query.bindValue(":id",edition::selected);
    query.exec();
    absence::model->setQuery(query);
    model->setHeaderData(0,Qt::Orientation::Horizontal,QString("date"));
    model->setHeaderData(1,Qt::Orientation::Horizontal,QString("heures d'absences"));
    ui->tableView->setModel(absence::model);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->hide();
}

absence::~absence()
{
    delete ui;
}

void absence::on_toolButton_clicked()
{
    addabsence dialog;
    dialog.exec();
}




void absence::on_toolButton_2_clicked()
{

}

