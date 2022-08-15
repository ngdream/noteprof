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
   public slots:
    void onselectionChanged();

 signals:
void selectionchanged();
};

#endif // TEACHERTABLE_H
