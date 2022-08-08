#ifndef ADDTEACHER_H
#define ADDTEACHER_H

#include <QDialog>
#include "defs.h"
namespace Ui {
class addteacher;
}

class addteacher : public QDialog
{
    Q_OBJECT

public:
    explicit addteacher(QWidget *parent = nullptr);
    ~addteacher();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addteacher *ui;
};

#endif // ADDTEACHER_H
