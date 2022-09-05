#include "delay.h"
#include "ui_delay.h"
#include"edition.h"
    QSqlQueryModel *delay::model;
delay::delay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delay)
{
    ui->setupUi(this);
    delay::model= new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT mdata,value FROM delay WHERE notationid =(:notation)");
    query.bindValue(":notation",edition::selected);

    query.exec();
    delay::model->setQuery(query);
    model->setHeaderData(0,Qt::Orientation::Horizontal,QString("date"));
     model->setHeaderData(1,Qt::Orientation::Horizontal,QString("minutes de retards"));
    ui->tableView->setModel(delay::model);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->hide();

}

delay::~delay()
{
    delete ui;
}

void delay::on_toolButton_clicked()
{
    adddelay dialog;
    dialog.exec();

}


void delay::on_toolButton_2_clicked()
{

}

