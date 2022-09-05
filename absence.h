#ifndef ABSENCE_H
#define ABSENCE_H

#include <QDialog>
#include"defs.h"
#include "addabsence.h"


namespace Ui {
class absence;
}

class absence : public QDialog
{
    Q_OBJECT

public:
    explicit absence(QWidget *parent = nullptr);
    QSqlQueryModel static *model;
    ~absence();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::absence *ui;
};

#endif // ABSENCE_H
