#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>

/**
 * @brief 通用树形结构类
 */
class TreeItem
{
public:
    TreeItem(const QList<QVariant> &data,TreeItem *parent=0 );
    ~TreeItem();

    void appendChild(TreeItem *child);
    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem *parent();

private:
    TreeItem *parentItem;  // 父结点
    QList<TreeItem*> childItems; // 子结点列表
    QList<QVariant> itemData; // 子节点对应数据
};

#endif // TREEITEM_H
