#include "edition.h"
#include "ui_edition.h"
#include "teachertable.h"
#include <QtPrintSupport/QtPrintSupport>
int edition::selected;
edition::edition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edition)
{
    ui->setupUi(this);
    model= new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT id,slug,trimestre  FROM notation WHERE teacherid =(:id)");
    query.bindValue(":id",Teachertable::selected);
    query.exec();

    model->setQuery(query);

    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->hide();
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnHidden(2,true);





    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged,
  this,&edition::onselectionchanged
);
    if(model->rowCount())
    {
    QModelIndex index =model->index(0,0);
    ui->tableView->setCurrentIndex(index);
    ui->label_52->hide();

    }
    else
    {
        ui->tabWidget->hide();



    }
}

void edition::onselectionchanged()
{


    QModelIndex index=ui->tableView->currentIndex();

        if(index.row()!=-1)
        {
    QVariant id=index.sibling(index.row(),0).data();
    edition::selected=id.value<int>();

        }

    QSqlQuery query;
    query.prepare("SELECT *  FROM notation WHERE ID =(:id)");
    query.bindValue(":id",edition::selected);
    query.exec();
    query.next();
    qDebug()<<query.value(1).toString()<<Teachertable::selected;
/*    QFile f("notebase.htm");
    f.open(QFile::ReadOnly);
QString html;
    QTextStream in(&html);
    in<<"<html ><head><title>yo</title></head><body style=\" text-align:center\">nnnn</body></html>";
    QTextDocument doc;
    QString str=QString(f.readAll());
    qDebug()<<str;

    QPrinter printer;
        printer.setOutputFormat(QPrinter::NativeFormat);
        //printer.setOutputFileName("nonwritable.pdf");
        QPrintDialog printDialog(&printer);
        if (printDialog.exec() == QDialog::Accepted) {
            QSizeF paperSize;
            paperSize.setWidth(printer.width());
            paperSize.setHeight(printer.height());
            doc.setHtml(str);
            doc.setPageSize(paperSize);
            doc.print(&printer);
        }

   /*     QPainter painter;
    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");

    }
    painter.begin(&printer);

          painter.translate(0,200);
          painter.drawLine(0, 0, 0, - painter.transform().dy());
painter.drawText(10, 10, "Test");
          painter.translate(189,189);
          painter.drawText(10, 10, "Test");
//printer.newPage();*/


    ui->pc->setChecked((query.value(7).toBool()==true)?true:false);
    ui->pr->setChecked((query.value(8).toBool()==true)?true:false);
    ui->ps->setChecked((query.value(9).toBool()==true)?true:false);
    ui->pag->setChecked((query.value(10).toBool()==true)?true:false);
    ui->ace->setValue(query.value(11).toInt());
     ui->acc->setValue(query.value(12).toInt());
      ui->ra->setChecked((query.value(13).toBool()==true)?true:false);
       ui->ei->setChecked((query.value(14).toBool()==true)?true:false);
    qDebug()<<"la selection de la fiche de notation à changé";

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

