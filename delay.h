#ifndef DELAY_H
#define DELAY_H

#include <QDialog>
#include "adddelay.h"
#include "defs.h"
namespace Ui {
class delay;
}

class delay : public QDialog
{
    Q_OBJECT

public:
    explicit delay(QWidget *parent = nullptr);
    QSqlQueryModel static *model;
    ~delay();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::delay *ui;
};

#endif // DELAY_H
