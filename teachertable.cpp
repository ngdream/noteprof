#include "teachertable.h"
#include <QMessageBox>
int Teachertable::selected;

Teachertable::Teachertable(QWidget *parent)
{
this->setFocusPolicy(Qt::NoFocus);

}

void Teachertable::selectionChanged(const QItemSelection &, const QItemSelection &)
{

    this->update();
    QModelIndex index=this->currentIndex();
if(index.row()!=-1)
{
    QVariant id=index.sibling(index.row(),4).data();
    Teachertable::selected=id.value<int>();

}
emit selectionchanged();


}
