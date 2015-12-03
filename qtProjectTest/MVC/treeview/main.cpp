#include <QApplication>
#include <QTextCodec>
#include <QTreeView>

#include "TagTreeModel.h"

int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    TagTreeModel model;

    QTreeView view;
    view.setModel(&model);
	view.setAlternatingRowColors(true);
    view.show();

    return app.exec();
}
