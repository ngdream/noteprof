#ifndef ADDABSENCE_H
#define ADDABSENCE_H

#include <QDialog>

namespace Ui {
class addabsence;
}

class addabsence : public QDialog
{
    Q_OBJECT

public:
    explicit addabsence(QWidget *parent = nullptr);
    ~addabsence();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addabsence *ui;
};

#endif // ADDABSENCE_H
