/**
 * @file main.cpp
 * @brief  
 * @author xiangxw
 * @version 0.0
 * @date 2011年04月30日
 */

#include<QApplication>
#include"MyTableView.h"


int main(int argc,char *argv[])
{
	QApplication app(argc,argv);

	MyTableView * table=new MyTableView;
	table->show();
   // table->setIndexWidget();
	return app.exec();
}
