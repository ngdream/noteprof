#include "editteacher.h"
#include "ui_editteacher.h"
#include "defs.h"
#include "teachertable.h"

editteacher::editteacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editteacher)
{

    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT *  FROM teacher WHERE ID =(:id)");
    query.bindValue(":id",Teachertable::selected);
    query.exec();
    query.next();

    ui->nomLineEdit->setText(query.value(0).toString());
    ui->prenomLineEdit->setText(query.value(1).toString());
    ui->sexComboBox->setCurrentIndex((query.value(2).toString()=="feminin")?1:0);
    ui->matriculeLineEdit->setText(query.value(3).toString());
}

editteacher::~editteacher()
{
    delete ui;
}

void editteacher::on_buttonBox_accepted()
{
    // add a new teacher in  database
    QSqlQuery query;
    query.prepare("update teacher set name=(:name),first_name=(:first_name),sex = (:sex),matricule = (:matricule)  where ID=(:id)");
    query.bindValue(":name",ui->nomLineEdit->text());
    query.bindValue(":first_name", ui->prenomLineEdit->text());
    query.bindValue(":sex",ui->sexComboBox->currentText());
    query.bindValue(":matricule",ui->matriculeLineEdit->text());
    query.bindValue(":id",Teachertable::selected);
    qDebug()<<query.lastQuery();

    query.exec();
    Teachertable::model->select();
}

