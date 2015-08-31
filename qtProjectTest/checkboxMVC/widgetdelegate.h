#ifndef WIDGETDELEGATE_H
#define WIDGETDELEGATE_H

#include <QItemDelegate>
#include "dewidget.h"

class WidgetDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit WidgetDelegate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, \
                          const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, \
                      const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,\
                              const QModelIndex &index) const;
    
signals:
    
public slots:

    
};

#endif // WIDGETDELEGATE_H
