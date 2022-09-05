#include "addabsence.h"
#include "ui_addabsence.h"
#include "defs.h"
#include "edition.h"


addabsence::addabsence(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addabsence)
{
    ui->setupUi(this);
}

addabsence::~addabsence()
{
    delete ui;
}

void addabsence::on_buttonBox_accepted()
{
    QSqlQuery query;
    query.prepare("INSERT INTO absence (mdata , notationid,value) VALUES (:date , :notation,:value)");
    query.bindValue(":date",ui->dateDateEdit->text());
    query.bindValue(":value",ui->heureSpinBox->value());
    query.bindValue(":notation",edition::selected);
    query.exec();



    absence::model->fetchMore();
    QSqlQuery q = absence::model->query();
    q.exec();
    absence::model->setQuery(q);
}

