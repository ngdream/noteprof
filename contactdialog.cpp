#include "contactdialog.h"
#include "ui_contactdialog.h"

contactdialog::contactdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contactdialog)
{
    ui->setupUi(this);
}

contactdialog::~contactdialog()
{
    delete ui;
}
