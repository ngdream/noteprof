#ifndef TEACHERTABLE_H
#define TEACHERTABLE_H

#include <QObject>
#include<qtableview.h>
#include"defs.h"

class Teachertable:public  QTableView
{
    Q_OBJECT
public:
    QSqlTableModel static *model;
    explicit Teachertable(QWidget *parent = nullptr);

static int selected;

};

#endif // TEACHERTABLE_H
