#ifndef EDITION_H
#define EDITION_H

#include <QWidget>

namespace Ui {
class edition;
}

class edition : public QWidget
{
    Q_OBJECT

public:
    explicit edition(QWidget *parent = nullptr);
    ~edition();

private:
    Ui::edition *ui;
};

#endif // EDITION_H
