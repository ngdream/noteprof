#include "addteacher.h"
#include "ui_addteacher.h"

addteacher::addteacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addteacher)
{
    ui->setupUi(this);




}

addteacher::~addteacher()
{
    delete ui;
}

void addteacher::on_buttonBox_accepted()
{    int age=ui->ageSpinBox->value();
     QString name = ui ->nomLineEdit->text();
     QString first_name=ui->prenomLineEdit->text();
QSqlQuery query;
      query.prepare("INSERT INTO teacher (name) VALUES (:name)");
      query.bindValue(":name", name);
      query.exec();

}

