#ifndef EDITTEACHER_H
#define EDITTEACHER_H

#include <QDialog>

namespace Ui {
class editteacher;
}

class editteacher : public QDialog
{
    Q_OBJECT

public:
    explicit editteacher(QWidget *parent = nullptr);
    ~editteacher();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::editteacher *ui;
};

#endif // EDITTEACHER_H
