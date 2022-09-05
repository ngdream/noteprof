#ifndef ADDDELAY_H
#define ADDDELAY_H

#include <QDialog>

namespace Ui {
class adddelay;
}

class adddelay : public QDialog
{
    Q_OBJECT

public:
    explicit adddelay(QWidget *parent = nullptr);
    ~adddelay();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::adddelay *ui;
};

#endif // ADDDELAY_H
