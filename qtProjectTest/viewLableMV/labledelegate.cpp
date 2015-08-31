#include "labledelegate.h"


LableDelegate::LableDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}
QWidget *LableDelegate::createEditor(QWidget *parent,\
             const QStyleOptionViewItem& option,const QModelIndex &index) const
{
    QLabel * lable=new QLabel(parent);
    return lable;
}

//把model的数据拷贝到编辑器中
void LableDelegate::setEditorData(QWidget * editor,const QModelIndex & index)const
{
    QString vale=index.model()->data(index,Qt::DisplayRole).toString();
    QLabel * label=(QLabel *)editor;
    label->setText(vale);
}
//向model提交数据
void LableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &indexconst)const
{
    QLabel * lable=(QLabel *)editor;
}
//更新编辑器的几何布局
void LableDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
     editor->setGeometry(option.rect);
}
