#include "edition.h"
#include "ui_edition.h"
#include "teachertable.h"
#include <QtPrintSupport/QtPrintSupport>


//unused
void edition::on_spinBox_4_valueChanged(int arg1){}
void edition::on_spinBox_3_valueChanged(int arg1){}
void edition::on_rds_textChanged(QString const &){}
void edition::on_callreg_textChanged(QString const &){}
void edition::on_checkBox_8_stateChanged(int arg1){}
void edition::on_spinBox_10_valueChanged(int arg1){}


int edition::selected;

edition::edition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edition)
{
    ui->setupUi(this);
    edition::model= new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT id,slug,trimestre  FROM notation WHERE teacherid =(:id)");
    query.bindValue(":id",Teachertable::selected);
    query.exec();

    edition::model->setQuery(query);

    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->hide();
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnHidden(2,true);

    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged,this,&edition::onselectionchanged);
    if(edition::model->rowCount())
    {
        QModelIndex index =edition::model->index(0,0);
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
  QFile f("notebase.htm");
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

    //punctuality
    ui->em->setValue(query.value(7).toInt());
    ui->pc->setChecked((query.value(8).toBool()==true)?true:false);
    ui->pr->setChecked((query.value(9).toBool()==true)?true:false);
    ui->ps->setChecked((query.value(10).toBool()==true)?true:false);
    ui->pag->setChecked((query.value(11).toBool()==true)?true:false);
    ui->ace->setValue(query.value(12).toInt());
    ui->acc->setValue(query.value(13).toInt());
    ui->ra->setChecked((query.value(14).toBool()==true)?true:false);
    ui->ei->setChecked((query.value(15).toBool()==true)?true:false);
    ui->re->setChecked((query.value(16).toBool()==true)?true:false);
    ui->car->setChecked((query.value(17).toBool()==true)?true:false);
    ui->tv->setChecked((query.value(18).toBool()==true)?true:false);
    ui->r->setValue(query.value(19).toInt());
     ui->ma->setValue(query.value(20).toInt());
     ui->cl->setChecked((query.value(21).toBool()==true)?true:false);

     //document
     ui->modc->setChecked((query.value(22).toBool()==true)?true:false);
     ui->chapc->setChecked((query.value(23).toBool()==true)?true:false);
     ui->ca->setChecked((query.value(24).toBool()==true)?true:false);
     ui->ai->setChecked((query.value(25).toBool()==true)?true:false);
     ui->stat->setChecked((query.value(26).toBool()==true)?true:false);
     ui->rdate->setChecked((query.value(27).toBool()==true)?true:false);
     ui->th->setChecked((query.value(28).toBool()==true)?true:false);
     ui->planc->setChecked((query.value(29).toBool()==true)?true:false);
     ui->updatec->setChecked((query.value(30).toBool()==true)?true:false);
     ui->callreg->setValue(query.value(31).toInt());


     //note
     ui->cs->setChecked((query.value(32).toBool()==true)?true:false);
     ui->cc->setChecked((query.value(33).toBool()==true)?true:false);
     ui->rds->setValue(query.value(34).toInt());
     ui->qs->setChecked((query.value(35).toBool()==true)?true:false);
     ui->rdn->setValue(query.value(36).toInt());
     ui->renh->setChecked((query.value(37).toBool()==true)?true:false);

     ui->rpp->setChecked((query.value(38).toBool()==true)?true:false);
     ui->fpc->setChecked((query.value(39).toBool()==true)?true:false);
     ui->cp->setChecked((query.value(40).toBool()==true)?true:false);
     ui->fp->setChecked((query.value(41).toBool()==true)?true:false);
     ui->rch->setChecked((query.value(42).toBool()==true)?true:false);
     ui->qc->setChecked((query.value(43).toBool()==true)?true:false);

    ui->mvt->setValue(query.value(44).toInt());
    ui->mvc->setValue(query.value(45).toInt());
    ui->sp->setChecked((query.value(46).toBool()==true)?true:false);
    ui->dfsp->setChecked((query.value(47).toBool()==true)?true:false);
    ui->drce->setChecked((query.value(48).toBool()==true)?true:false);
    ui->prc->setChecked((query.value(49).toBool()==true)?true:false);
     ui->rpe->setChecked((query.value(50).toBool()==true)?true:false);
    ui->dsp->setChecked((query.value(51).toBool()==true)?true:false);
    ui->dch->setChecked((query.value(52).toBool()==true)?true:false);




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

void edition::on_em_valueChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set em = (:val) where id=(:id)");
    query.bindValue(":val",arg1);
    query.bindValue(":id",edition::selected);
    qDebug()<<arg1;
    query.exec();
}

void edition::on_pc_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set pc = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_pr_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set pr = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_ps_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set ps = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_pag_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set pag = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_ace_valueChanged(int arg1)
{
    QSqlQuery query;
            query.prepare("UPDATE notation set ace = (:val) where id=(:id)");
    query.bindValue(":val",arg1);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_acc_valueChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set acc = (:val) where id=(:id)");
    query.bindValue(":val",arg1);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_ra_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set ra = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_ei_stateChanged(int arg1)
{
    QSqlQuery query;
            query.prepare("UPDATE notation set ei = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_re_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set re = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_car_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set car = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_tv_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set tv = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_r_valueChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set r = (:val) where id=(:id)");
    query.bindValue(":val",arg1);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_cl_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set cl = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_modc_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set modc = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_chapc_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set chap = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_ca_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set ca = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_stat_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set stat = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_rdate_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set rdate = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_planc_stateChanged(int arg1)
{
    QSqlQuery query;
            query.prepare("UPDATE notation set planc = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}


void edition::on_updatec_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set updatec = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}


void edition::on_cs_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set cs = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}


void edition::on_cc_stateChanged(int arg1)
{
    QSqlQuery query;
            query.prepare("UPDATE notation set cc = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}




void edition::on_rds_valueChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set rds = (:val) where id=(:id)");
    query.bindValue(":val",arg1);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_callreg_valueChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set callreg = (:val) where id=(:id)");
    query.bindValue(":val",arg1);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_qs_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set qs = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_rdn_valueChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set rdn = (:val) where id=(:id)");
    query.bindValue(":val",arg1);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_renh_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set renh = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_ai_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set ai = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_ma_valueChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set ma = (:val) where id=(:id)");
    query.bindValue(":val",arg1);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_th_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set th = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_qc_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set qc = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_rch_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set rch = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_fp_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set fp = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}


void edition::on_cp_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set cp = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}


void edition::on_fpc_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set fpc = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}





void edition::on_rpp_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set rpp = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_mvt_valueChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set mvt = (:val) where id=(:id)");
    query.bindValue(":val",arg1);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_mvc_valueChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set mvc = (:val) where id=(:id)");
    query.bindValue(":val",arg1);
    query.bindValue(":id",edition::selected);
    query.exec();
}



void edition::on_sp_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set sp = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}


void edition::on_dfsp_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set dfsp = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}


void edition::on_drce_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set drce = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}


void edition::on_prc_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set prc = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}


void edition::on_rpe_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set rpe = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_dsp_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set dsp = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}

void edition::on_dch_stateChanged(int arg1)
{
    QSqlQuery query;
    query.prepare("UPDATE notation set dch = (:val) where id=(:id)");
    query.bindValue(":val",(arg1==Qt::Unchecked)?false:true);
    query.bindValue(":id",edition::selected);
    query.exec();
}


void edition::on_toolButton_clicked()
{
    QSqlQuery query;
    query.prepare("delete from notation where id=(:id)");
    query.bindValue(":id",edition::selected);
    query.exec();

}

