#ifndef WRITESHAREDMEMORY_H
#define WRITESHAREDMEMORY_H

#include <QtGui/QMainWindow>
#include "ui_WriteSharedMemory.h"
#include <QSharedMemory>
#include <QSystemSemaphore>
class WriteSharedMemory : public QMainWindow
{
	Q_OBJECT

public:
	WriteSharedMemory(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WriteSharedMemory();
	///可用空间
	static	QSystemSemaphore freeSystemSem;
	///已用空间
	static	QSystemSemaphore usedSystemSem;
public slots:
	///写入共享内存
	void loadIntoSharedMem();
	void init();
	void write();
	QString read();
	///循环写
	void run();
	void detach();

	 
private:
	Ui::WriteSharedMemoryClass ui;
	QSharedMemory sharedMem;
	int  num;
};

#endif // WRITESHAREDMEMORY_H
