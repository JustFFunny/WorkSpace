#ifndef LABLEDELEGATE_H
#define LABLEDELEGATE_H

#include <QItemDelegate>
#include <QLabel>

class LableDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit LableDelegate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent,\
                 const QStyleOptionViewItem& option,const QModelIndex &index) const;

    //把model的数据拷贝到编辑器中
    void setEditorData(QWidget * editor,const QModelIndex & index)const;
    //向model提交数据
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &indexconst)const;
    //更新编辑器的几何布局
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    
signals:
    
public slots:
    
};

#endif // LABLEDELEGATE_H
