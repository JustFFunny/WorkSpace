#include "contactwidget.h"
#include "ui_contactwidget.h"

ContactWidget::ContactWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactWidget)
{
    ui->setupUi(this);
    this->setLayout(ui->horizontalLayout);


    QSettings settings;
    ip = settings.value("wlanIP").toString();
    port = settings.value("sPort").toInt();

    contactsMap = new QMap<QString,Contact>();
    tableWidget = ui->tableWidget;
    //connect(tableWidget, SIGNAL(currentTextChanged(QString)), this, SLOT(showInfo(QString)));

    //connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(addContact()));
    //connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(delContact()));

    getContactList();

}

ContactWidget::~ContactWidget()
{
    delete ui;
}

void ContactWidget::getContactList()
{
    QString mesg = "CONTACT:GET\n";
    socket = new QTcpSocket();
    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        connect(socket, SIGNAL(readyRead()), this, SLOT(readContactInfo()));
        connect(socket, SIGNAL(readChannelFinished()),this,SLOT(readContactInfoFished()));
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }
}
void ContactWidget::readContactInfo()
{
    bool b = socket->canReadLine();
    while(socket->canReadLine())
    {
        QString output= QString::fromUtf8(socket->readLine());

        if (output.contains(QRegExp("^GET_CONTACT_LIST:")))
        {
            output.remove(QRegExp("^GET_CONTACT_LIST:"));
            QString id,number,name;
            int i;
            i = output.indexOf(":");
            id = output.left(i);
            output.remove(0,i+1);

            i = output.indexOf(":");
            name = output.left(i);
            output.remove(0,i+1);

            i = output.indexOf(":");
            number = output;
            number.remove("\n");
            Contact con (id,number,name);
            QString tmp = name+"("+number+")";
            contactsMap->insert(tmp,con);

            QIcon *qicon = new QIcon();
            qicon->addFile(":icons/contactDefault.png");

            QTableWidgetItem *item_qicon = new QTableWidgetItem(*qicon,"");

            QTableWidgetItem *item_name = new QTableWidgetItem(con.getName());

            QTableWidgetItem *item_num = new QTableWidgetItem(con.getNumber());


            //返回列表中的行数
            int current_rows = tableWidget->rowCount();
            tableWidget->insertRow(current_rows);
            tableWidget->setItem(current_rows, 0, item_qicon);
            tableWidget->setItem(current_rows, 1, item_name);
            tableWidget->setItem(current_rows, 2, item_num);

        }
    }
}
void ContactWidget::readContactInfoFished()
{
    disconnect(socket, SIGNAL(readyRead()), this, SLOT(readContactInfo()));
    disconnect(socket, SIGNAL(readChannelFinished()),this,SLOT(readContactInfoFished()));
    socket->disconnectFromHost();
    socket->close();
}

void ContactWidget::showInfo(QString msg)
{
    if(contactsMap->contains(msg))
    {
        QMap<QString,Contact>::iterator it = contactsMap->find(msg);
        Contact c = it.value();
        ui->lineEditContactsId->setText(c.getId());
        ui->lineEditContactsName->setText(c.getName());
        ui->lineEditContactsNumber->setText(c.getNumber());
    }
}

void ContactWidget::addContact()
{
    this->contactDialog = new ContactDialog;

    int result = this->contactDialog->exec();
    if (result == 1)
    {
        QString name  = this->contactDialog->lineEdit_name->text();
        QString number = this->contactDialog->lineEdit_number->text();

        QString mesg = "CONTACT:ADD:";
        mesg.append(name);
        mesg.append(":");
        mesg.append(number);
        mesg.append("\n");

        socket = new QTcpSocket();
        //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
        socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
        if (socket->waitForConnected(2000))
        {
            socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
            socket->waitForBytesWritten();
        }
        if(socket->waitForReadyRead(-1))
        {
            QString readData = QString::fromUtf8(socket->readAll());
            QString id = readData.split("\n")[0];

            Contact con (id,number,name);
            QString tmp = name+"("+number+")";
            contactsMap->insert(tmp,con);
            //listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr(":icons/contactDefault.png")), tmp));

        }
        socket->disconnectFromHost();

    }
    delete this->contactDialog;

}
void ContactWidget::delContact()
{
//   QListWidgetItem *item = listWidget->currentItem();
//   if(item != NULL)
//   {
//       QString msg = item->text();
//       QMap<QString,Contact>::iterator it = contactsMap->find(msg);
//       Contact c = it.value();
//       QString number = c.getNumber();

//       QString mesg = "CONTACT:DELETE:";
//       mesg.append(number);
//       mesg.append("\n");
//       socket = new QTcpSocket();
//       //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
//       socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
//       if (socket->waitForConnected(2000))
//       {
//           socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
//           socket->waitForBytesWritten();
//       }
//       if(socket->waitForReadyRead(-1))
//       {
//           QString readData = QString::fromUtf8(socket->readAll());
//           QString result = readData.split("\n")[0];
//       }
//       socket->disconnectFromHost();

//       contactsMap->remove(msg);
//       int row = ui->listWidget->currentRow();
//       ui->listWidget->takeItem(row);
//       ui->lineEditContactsId->setText("");
//       ui->lineEditContactsName->setText("");
//       ui->lineEditContactsNumber->setText("");
//   }
}
