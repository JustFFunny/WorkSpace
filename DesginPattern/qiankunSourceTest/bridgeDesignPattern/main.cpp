//bridge design Pattern 主要是把抽象和现实分离出来，使他们都有各自的变化。
//使用在 多维变化。eg:画什么 和 在那画。
//如果是一维的变化，可以用继承来实现，比如，三星，在pdf上画，在doc上画；
//可以使用定义个抽象的画板类，然后pdf画板 和doc画板分别继承画板类，然后实现。
#include <iostream>
#include <list>

struct Point
{
    int x;
    int y;
};

using namespace std;

class DrawBoard //画板
{
public:
    DrawBoard(){};
    ~DrawBoard(){};
    virtual void draw(){};
};

class pdfDraw:public DrawBoard
{
public:
    pdfDraw(){}
    ~pdfDraw(){}
    void draw()
    {
        cout<<"pdfDraw\n";
    }
};


class DocDraw:public DrawBoard
{
public:
    DocDraw(){}
    ~DocDraw(){}
    void draw()
    {
        cout<<"DocDraw\n";
    }
};

//抽象类 形状
class Shape
{
public:
    Shape() {}
    ~Shape(){}
    virtual void draw()
    {
        m_drawBoard->draw();
    }
    DrawBoard* m_drawBoard;
private:
    list<Point> m_pointList;

};

class Circle:public Shape
{
public:
    Circle(){  cout<<"Circle\n";}
    ~Circle(){}
};

class Rectangle:public Shape
{
public:
    Rectangle()
    {
       cout<<"Rectangle\n";
    }
    ~ Rectangle() {}
};

int main()
{
    cout << "Hello World!" << endl;
    Shape * _shape=new Circle;
    _shape->m_drawBoard=new pdfDraw;
    _shape->draw();

    cout<<"******************\n";

    _shape=new Rectangle;
    _shape->m_drawBoard= new DocDraw;
    _shape->draw();


    return 0;
}

