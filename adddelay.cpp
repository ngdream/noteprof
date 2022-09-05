#include "adddelay.h"
#include "ui_adddelay.h"
#include "edition.h"


adddelay::adddelay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adddelay)
{
    ui->setupUi(this);
}

adddelay::~adddelay()
{
    delete ui;
}

void adddelay::on_buttonBox_accepted()
{
    QSqlQuery query;
    query.prepare("INSERT INTO delay ( notationid , mdata , value) VALUES ( :notation , :date , :value)");
    query.bindValue(":notation",edition::selected);
     query.bindValue(":date",ui->dateDateEdit->text());
     query.bindValue(":value",ui->minutesSpinBox->value());
    query.exec();

    delay::model->fetchMore();
    QSqlQuery q = delay::model->query();
    q.exec();
    delay::model->setQuery(q);
}

