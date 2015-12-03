#include "widgetdelegate.h"

WidgetDelegate::WidgetDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}

QWidget * WidgetDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, \
                      const QModelIndex &index) const
{
    DeWidget * dewidget=new DeWidget(parent);
    return dewidget;
}
void WidgetDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, \
                  const QModelIndex &index) const
{
}
void WidgetDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,\
                          const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
