#ifndef READSHAREDMEMORY_H
#define READSHAREDMEMORY_H

#include <QtGui/QMainWindow>
#include "ui_ReadSharedMemory.h"
#include <QSharedMemory>
#include <QSystemSemaphore>
class ReadSharedMemory : public QMainWindow
{
	Q_OBJECT

public:
	ReadSharedMemory(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ReadSharedMemory();
	///可用空间
	static	QSystemSemaphore freeSystemSem;
	///已用空间
	static	QSystemSemaphore usedSystemSem;
public slots:
	///读取共享内存
	void loadFromSharedMem();
	void read();
	///循环读
	void run();
	void detach();
	void attach();
private:
	Ui::ReadSharedMemoryClass ui;
	QSharedMemory sharedMem;
};

#endif // READSHAREDMEMORY_H
