#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <QDialog>

namespace Ui {
class contactdialog;
}

class contactdialog : public QDialog
{
    Q_OBJECT

public:
    explicit contactdialog(QWidget *parent = nullptr);
    ~contactdialog();

private:
    Ui::contactdialog *ui;
};

#endif // CONTACTDIALOG_H
