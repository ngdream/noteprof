#ifndef ADDNOTE_H
#define ADDNOTE_H

#include <QDialog>
#include"defs.h"
namespace Ui {
class addnote;
}

class addnote : public QDialog
{
    Q_OBJECT

public:
    explicit addnote(QWidget *parent = nullptr);
    ~addnote();

private slots:
    void on_addnote_accepted();

private:
    Ui::addnote *ui;
};

#endif // ADDNOTE_H
