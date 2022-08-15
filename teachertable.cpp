#include "teachertable.h"
#include <QMessageBox>
int Teachertable::selected;

Teachertable::Teachertable(QWidget *parent)
{
this->setFocusPolicy(Qt::NoFocus);

    connect(this,
            SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
                   this,SLOT(onselectionChanged));
}

void Teachertable::onselectionChanged()
{


    QModelIndex index=this->currentIndex();


if(index.row()!=-1)
{
    QVariant id=index.sibling(index.row(),4).data();
    Teachertable::selected=id.value<int>();

}

//QMessageBox::information(this,"change","selection changed");
emit selectionchanged();


}

