#include <QApplication>
#include <QLineEdit>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLineEdit * _lineEdit=new QLineEdit;
    _lineEdit->setFixedSize(100,50);


    _lineEdit->setText("hello world 2015/1/12");
    _lineEdit->setAlignment(Qt::AlignLeft);
    // _lineEdit->setCursorPosition(0);

    _lineEdit->show();
    return a.exec();
}
