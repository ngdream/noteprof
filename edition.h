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

private slots:
    void on_toolButton_2_clicked();

private:
    Ui::edition *ui;
    QSqlQueryModel *model;
};

#endif // EDITION_H
