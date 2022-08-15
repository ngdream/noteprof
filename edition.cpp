#include "edition.h"
#include "ui_edition.h"
#include "teachertable.h"

edition::edition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edition)
{
    ui->setupUi(this);
    model= new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT id  FROM notation WHERE teacherid =(:id)");
    query.bindValue(":id",Teachertable::selected);
    query.exec();
    model->setQuery(query);
    ui->listView->setModel(model);

}

edition::~edition()
{
    delete ui;
}

void edition::on_toolButton_2_clicked()
{
addnote dialog(this);

dialog.exec();
}

