#include "ReadSharedMemory.h"
#include <QBuffer>
#include <QDataStream>
#include <QDebug>
ReadSharedMemory::ReadSharedMemory(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags),sharedMem("MySharedMemory")
{
	ui.setupUi(this);
	connect(ui.showButton, SIGNAL(clicked()), SLOT(run()));
	connect(ui.detachBtn, SIGNAL(clicked()), SLOT(detach()));
	connect(ui.attachBtn, SIGNAL(clicked()), SLOT(attach()));

}

ReadSharedMemory::~ReadSharedMemory()
{

}

QSystemSemaphore ReadSharedMemory::freeSystemSem("freeFpga", 3, QSystemSemaphore::Open);
QSystemSemaphore ReadSharedMemory::usedSystemSem("usedFpga", 3, QSystemSemaphore::Open);

void ReadSharedMemory::read()
{
	if(sharedMem.isAttached())
	{
		//qDebug() << "ReadSharedMemory:: haved attached.";
	}
	else 
	{
		if(!sharedMem.attach()) 
		{
			//If an attempt of reading from the shared memory before data is written
			QSharedMemory::SharedMemoryError m = sharedMem.error();
			qDebug() << "ReadSharedMemory:: attach failed.";
			return;

		}
		else
		{
			qDebug() << "ReadSharedMemory:: attach success.";
		}
	}

	QBuffer buffer;
	QDataStream in(&buffer);
	QString text;

	usedSystemSem.acquire();
	sharedMem.lock();
	buffer.setData((char*)sharedMem.constData(), sharedMem.size());
	buffer.open(QBuffer::ReadOnly);
	in >> text;
	//Çå¿Õ»º´æ
	char* to = (char*)sharedMem.data();
	memset(to,0,sharedMem.size());
	sharedMem.unlock();

	freeSystemSem.release();
	
	// As this is the last process attached to the shared memory segment
	// the shared memory segment is released, destroying its contents
	//sharedMem.detach();
	ui.textEdit_2->append(text);
	QStringList fileList = text.split(";");


	QStringList::const_iterator constIterator;
	for (constIterator = fileList.constBegin(); constIterator < fileList.constEnd()-1;
		++constIterator)
	qDebug() <<"ReadSharedMemory:: Read:"<< (*constIterator).toLocal8Bit().constData();
}
void ReadSharedMemory::loadFromSharedMem()
{
	read();
}

void ReadSharedMemory::run()
{
	while(1)
	{
		loadFromSharedMem();
	}
}

void ReadSharedMemory::detach( )
{
	if (sharedMem.isAttached())
	{
		qDebug() << "attached";
		if(!sharedMem.detach())
			qDebug() << "ReadSharedMemory::detached failed.";
		else
			qDebug() << "ReadSharedMemory::detached success.";
	}

}

void ReadSharedMemory::attach()
{
	if(sharedMem.isAttached())
		ui.textEdit->append(tr("ReadSharedMemory:: sharedMem is attched by this process."));
	if (!sharedMem.attach()) 
	{
		//If an attempt of reading from the shared memory before data is written
		QSharedMemory::SharedMemoryError m = sharedMem.error();
		qDebug() << "ReadSharedMemory:: attach failed.";

	}
	else
	{
		qDebug() << "ReadSharedMemory:: attach success.";

	}
}