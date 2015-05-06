#include <QApplication>
#include <QLineEdit>
#include <QDebug>
#include <QProcess>
#include <QtScript/QtScript>

#include <QtWebKit/QWebView>
#include <QtWebKit>
#include <QPushButton>
#include <QLayout>
/*
 * 注意
 *1. .pro 中 QT+=script
 *2. 包含的头文件 #include <QtScript>
 *3. javaScript 的函数形式eg:
 *   Function  函数名(参数)
 *   {
 *     执行单元;
 *     返回值;
 *   }
 *4. QScriptEngine类为程序提供一个嵌入式脚本环境/
 *   通过调用脚本引擎的evaluate()函数可以执行脚本.
 *5.The QScriptValue class acts as a container for the Qt Script data types.
 **/

//C++调用 JavaScript  Function
void testScript()
{
    QScriptEngine myEngine;
    myEngine.evaluate("function cube(x) { return x * x * x; }    function mysqrt(x) { return Math.sqrt(x);} ");
    qDebug()<< myEngine.evaluate("mysqrt(cube(3.1))").toNumber();
}
void  testScriptFunctionCall()
{
    QScriptEngine engine;
    QScriptValue func = engine.evaluate("(function(a, b) { return a+b;})");
    QScriptValueList args;
    args << 1 << 2;
    QScriptValue result = func.call(QScriptValue(), args);
    qDebug() << "Result: " << result.toInt32();
}
void webCallScriptFun()
{
    QWebView * v=new QWebView;
   // QPushButton * b=new QPushButton;


    QScriptEngine engine;
    v->load(QUrl("/home/wuqiankun/webCallScript/test.html"));
    v->page()->mainFrame()->evaluateJavaScript("Test()");
    v->show();
   // b->show();
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //    QLineEdit * _lineEdit=new QLineEdit;
    //    _lineEdit->setFixedSize(100,50);


    //    _lineEdit->setText("hello world 2015/1/12");
    //    _lineEdit->setAlignment(Qt::AlignLeft);
    //    // _lineEdit->setCursorPosition(0);
    //    _lineEdit->show();
    //    QProcess * m_process=new QProcess;
    //    //explorer  是windows的资源管理可执行程序 linux没有这个programe
    //    m_process->startDetached(QString("explorer" )+QString(" /home/wuqiankun"));


    //testScript();
    //testScriptFunctionCall();
     webCallScriptFun();

    return a.exec();
}
