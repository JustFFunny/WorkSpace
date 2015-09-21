#include "WriteSharedMemory.h"
#include <QBuffer>
#include <QDebug>
WriteSharedMemory::WriteSharedMemory(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags),sharedMem("MySharedMemory")
{
	ui.setupUi(this);
	num = 0;
	init();
	//connect(ui.loadButton, SIGNAL(clicked()), SLOT(loadIntoSharedMem()));
	connect(ui.loadButton, SIGNAL(clicked()), SLOT(run()));
	connect(ui.initBtn, SIGNAL(clicked()), SLOT(init()));
	connect(ui.detachBtn, SIGNAL(clicked()), SLOT(detach()));
	
}

WriteSharedMemory::~WriteSharedMemory()
{

}

QSystemSemaphore WriteSharedMemory::freeSystemSem("freeFpga", 3, QSystemSemaphore::Create);
QSystemSemaphore WriteSharedMemory::usedSystemSem("usedFpga", 3, QSystemSemaphore::Create);

void WriteSharedMemory::init()
{
	// First, test whether a shared memory segment is already attached to the process.
	// If so, detach it
	if (sharedMem.isAttached())
	{
		if(!sharedMem.detach())
			
		{
			ui.textEdit->append("WriteSharedMemory : detach failed.");
			qDebug()<< "WriteSharedMemory : detach failed.";
			return;
		}
		

	}


	if ( !sharedMem.create( 1024 ) ) 
	{
		ui.textEdit->append(tr("Unable to create shared memory segment."));
		qDebug()<< "WriteSharedMemory::Unable to create shared memory segment.";
		return;
	}
	
}

void WriteSharedMemory::loadIntoSharedMem()
{
	write();
}
void WriteSharedMemory::run()
{
	while(1)
	{
		loadIntoSharedMem();
		_sleep(2);
	}
}


QString WriteSharedMemory::read()
{
	QBuffer buffer;
	QDataStream in(&buffer);
	QString text;

	sharedMem.lock();
	buffer.setData((char*)sharedMem.constData(), sharedMem.size());
	buffer.open(QBuffer::ReadOnly);
	in >> text;
	sharedMem.unlock();
	qDebug() << "WriteSharedMemory:: Read:" << text;
	return text;
}
void WriteSharedMemory::write( )
{
	
	QString text = read();

	QBuffer buffer;
	text = text + "C://project//projectFile" + QString::number(num) + ".txt;";
	

	buffer.open( QBuffer::ReadWrite );
	QDataStream out( &buffer );
	out << text;
	int size = buffer.size();

	if(sharedMem.size()<size)
	{
		qDebug() << "共享内存空间不够！";
		return ;
	}
	num++;

	freeSystemSem.acquire();
	// Write into the shared memory
	sharedMem.lock();
	char *to = (char*)sharedMem.data();
	const char *from = buffer.data().data();
	memcpy( to, from, qMin( sharedMem.size(), size ) );
	sharedMem.unlock();
	usedSystemSem.release();


	ui.textEdit_2->append(text);
	qDebug() << "WriteSharedMemory:: Write:" << text;
}

void WriteSharedMemory::detach( )
{
	if (sharedMem.isAttached())
	{
		qDebug() << "attached";
		if(!sharedMem.detach())
			ui.textEdit->append("WriteSharedMemory:: detach failed.");
		else
			qDebug() << "WriteSharedMemory:: detached success.";
	}

}