#include "edition.h"
#include "ui_edition.h"

edition::edition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edition)
{
    ui->setupUi(this);
}

edition::~edition()
{
    delete ui;
}
