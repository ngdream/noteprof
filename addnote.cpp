#include "addnote.h"
#include "ui_addnote.h"
#include "teachertable.h"
#include "edition.h"

QSqlQueryModel *edition::model;
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
     QString slug = ui->slugLineEdit->text();


     if(annee=="")
     {
         int day,month,year;
         QDateTime::currentDateTime().
         date().getDate(&year,&month,&day);

         if(month>1 && month<9)
         annee=QString::number(year-1)+"-"+QString::number(year);
         else
         annee=QString::number(year)+"-"+QString::number(year+1);
     }

   if(slug=="")
   slug=QString("fiche de notation") + " "+ trimestre + " "+ "année :"+annee;

   QSqlQuery query;
   query.prepare("INSERT INTO notation (disciplines,classes,trimestre,annee,teacherid,slug) VALUES (:discipline,:classes,:trimestre,:annee,:teacherid,:slug)");
   query.bindValue(":discipline",discipline);
   query.bindValue(":classes",classes);
   query.bindValue(":trimestre",trimestre);
   query.bindValue(":teacherid",Teachertable::selected);
   query.bindValue(":annee",annee);
   query.bindValue(":slug",slug);



  //works now!!


   edition::model->fetchMore();
   query.exec();
   QSqlQuery q = edition::model->query();
   q.exec();
   edition::model->setQuery(q);
}
