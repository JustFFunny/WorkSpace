#ifndef ICONDELEGATE_H
#define ICONDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
class IconDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit IconDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
signals:
    void row(const QModelIndex &);
public slots:
    
};

#endif // ICONDELEGATE_H
