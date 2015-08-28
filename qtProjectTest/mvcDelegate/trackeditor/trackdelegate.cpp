#include <QtGui>

#include "trackdelegate.h"

TrackDelegate::TrackDelegate(int durationColumn, QObject *parent)
    : QItemDelegate(parent)
{
    this->durationColumn = durationColumn;
}

void TrackDelegate::paint(QPainter *painter,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    //保存音轨的列
    if (index.column() == durationColumn) {
        //获得索引对应Model中的数据
        int secs = index.model()->data(index, Qt::DisplayRole).toInt();
        //设置时间格式字符串 分:秒
        QString text = QString("%1:%2")
                       .arg(secs / 60, 2, 10, QChar('0'))
                       .arg(secs % 60, 2, 10, QChar('0'));
        //获取项风格设置
        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
        //绘制文本
        drawDisplay(painter, myOption, myOption.rect, text);
        //如果当前有焦点，就绘制一个焦点矩形，否则什么都不做
        drawFocus(painter, myOption, myOption.rect);
    } else{
        //否则默认
        QItemDelegate::paint(painter, option, index);
    }
}

QWidget *TrackDelegate::createEditor(QWidget *parent,
        const QStyleOptionViewItem &option,
        const QModelIndex &index) const
{
    //音轨时间列
    if (index.column() == durationColumn) {
        //时间编辑控件
        QTimeEdit *timeEdit = new QTimeEdit(parent);
        //时间编辑控件文本格式
        timeEdit->setDisplayFormat("mm:ss");
        //如果编辑结束，激活提交和关闭槽
        connect(timeEdit, SIGNAL(editingFinished()),
                this, SLOT(commitAndCloseEditor()));
        return timeEdit;
    } else {
        //否则使用默认委托处理
        return QItemDelegate::createEditor(parent, option, index);
    }
}
//设置控件值
void TrackDelegate::setEditorData(QWidget *editor,
                                  const QModelIndex &index) const
{
    //音轨时间列
    if (index.column() == durationColumn) {
        //获得当前索引在Model中的值
        int secs = index.model()->data(index, Qt::DisplayRole).toInt();
        //设置时间控件的值
        QTimeEdit *timeEdit = qobject_cast<QTimeEdit *>(editor);
        timeEdit->setTime(QTime(0, secs / 60, secs % 60));
    } else {
        QItemDelegate::setEditorData(editor, index);
    }
}
//设置Model值
void TrackDelegate::setModelData(QWidget *editor,
                                 QAbstractItemModel *model,
                                 const QModelIndex &index) const
{
    //音轨列
    if (index.column() == durationColumn) {
        //获得时间控件值
        QTimeEdit *timeEdit = qobject_cast<QTimeEdit *>(editor);
        QTime time = timeEdit->time();
        int secs = (time.minute() * 60) + time.second();
        //设置模型值
        model->setData(index, secs);
    } else {
        //否则使用默认委托处理
        QItemDelegate::setModelData(editor, model, index);
    }
}
//自定义 提交和关闭 槽函数
void TrackDelegate::commitAndCloseEditor()
{
    QTimeEdit *editor = qobject_cast<QTimeEdit *>(sender());
    //提交该控件的值 否则模型中数据不更改
    emit commitData(editor);
    //关闭该控件 可以告知委托去代开下一个控件
    emit closeEditor(editor);
}
