#include "WriteSharedMemory.h"
#include <QtGui/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	// 以下部分解决中文乱码  
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));  
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));  
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));  
	// 以上部分解决中文乱码  
	WriteSharedMemory w;
	w.show();
	
	return a.exec();
}
