#ifndef EDITION_H
#define EDITION_H

#include <QWidget>
#include "addnote.h"
namespace Ui {
class edition;
}

class edition : public QWidget
{
    Q_OBJECT

public:
    explicit edition(QWidget *parent = nullptr);
    ~edition();
    static int selected;
private slots:
    void on_toolButton_2_clicked();
    void onselectionchanged();
    void on_spinBox_10_valueChanged(int arg1);

    void on_pc_stateChanged(int arg1);

    void on_pr_stateChanged(int arg1);

    void on_ps_stateChanged(int arg1);

    void on_pag_stateChanged(int arg1);

    void on_ace_valueChanged(int arg1);

    void on_acc_valueChanged(int arg1);

    void on_ra_stateChanged(int arg1);

    void on_ei_stateChanged(int arg1);

    void on_re_stateChanged(int arg1);

    void on_checkBox_8_stateChanged(int arg1);

    void on_car_stateChanged(int arg1);

    void on_tv_stateChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_r_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_cl_stateChanged(int arg1);

    void on_modc_stateChanged(int arg1);

    void on_chapc_stateChanged(int arg1);

    void on_ca_stateChanged(int arg1);

    void on_stat_stateChanged(int arg1);

    void on_rdate_stateChanged(int arg1);

    void on_planc_stateChanged(int arg1);

    void on_updatec_stateChanged(int arg1);

    void on_callreg_textChanged(const QString &arg1);

    void on_cs_stateChanged(int arg1);

    void on_cc_stateChanged(int arg1);

    void on_rds_textChanged(const QString &arg1);

    void on_rds_valueChanged(int arg1);

    void on_callreg_valueChanged(int arg1);

    void on_qs_stateChanged(int arg1);

    void on_rdn_valueChanged(int arg1);

    void on_renh_stateChanged(int arg1);

    void on_em_valueChanged(int arg1);

    void on_ma_valueChanged(int arg1);

    void on_ai_stateChanged(int arg1);

    void on_th_stateChanged(int arg1);

private:
    Ui::edition *ui;
    QSqlQueryModel *model;
};

#endif // EDITION_H
