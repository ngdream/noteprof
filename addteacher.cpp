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

//add a teacher if ok buton is pressed
void addteacher::on_buttonBox_accepted()
{
    //get form data in dialog
     QString name = ui ->nomLineEdit->text();
     QString first_name=ui->prenomLineEdit->text();
     QString sex=ui->sexComboBox->currentText();
     QString matricule=ui->matriculeLineEdit->text();
     QString local_photo_path=ui->photoLineEdit->text();// get a local image to add


     //get the file name
     QFileInfo fileInfo(local_photo_path);
     QString filename(fileInfo.fileName());


     QString photo_path="";
    if(local_photo_path!="")
    {

        photo_path="./path/"+filename ;
        QFile photofile(photo_path);
     int i=0;
     while(photofile.isOpen())
     {


         photofile.close();
         QString filenameextend=filename;
         filenameextend.insert(filename.indexOf(QString(".")),QString::number(i));
         photo_path="./path/"+filenameextend ;
         photofile.setFileName(photo_path);
         photofile.open(QFile::ReadOnly);
         i++;
     }
     QFile::copy(local_photo_path,photo_path );
    }

      // add a new teacher in  database
      QSqlQuery query;
      query.prepare("INSERT INTO teacher (name,first_name,sex,matricule,photo_path) VALUES (:name,:first_name,:sex,:matricule,:photo_path)");
      query.bindValue(":name", name);
      query.bindValue(":first_name", first_name);
      query.bindValue(":sex",sex);
      query.bindValue(":matricule",matricule);
      query.bindValue(":photo_path",photo_path);
      query.exec();

}


void addteacher::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
    tr("select an image"), "/home", tr(" image files (*.jpg .png .svg .bmp)"));
    ui->photoLineEdit->setText(filename);
}

