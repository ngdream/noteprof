#include "addnote.h"
#include "ui_addnote.h"
#include "teachertable.h"



addnote::addnote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnote)
{
    ui->setupUi(this);
}

addnote::~addnote()
{
    delete ui;
}

void addnote::on_addnote_accepted()
{
    //get form data in dialog
     QString annee = ui ->annELineEdit->text();
     QString classes=ui->classesLineEdit->text();
     QString trimestre=ui->trimestreComboBox->currentText();
     QString discipline=ui->disciplineLineEdit->text();



    QSqlQuery query;
    query.prepare("INSERT INTO notation (disciplines,classes,trimestre,annee,teacherid) VALUES (:discipline,:classes,:trimestre,:annee,:teacherid)");
   query.bindValue(":discipline",discipline);
   query.bindValue(":classes",classes);
   query.bindValue(":trimestre",trimestre);
   query.bindValue(":teacherid",Teachertable::selected);
   query.bindValue(":annee",annee);
    query.exec();

}
