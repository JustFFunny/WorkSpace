#ifndef BASE_H
#define BASE_H

class Base
{
public:
    Base();
      virtual ~Base();
   // ~Base();
    virtual void doSome();
    virtual void  hello();
    void hide(float x);
    void hide_2(int x);
};
class Devrived :public Base
{
public:
    Devrived();
    ~Devrived();
    void doSome();
    void get();
    void hide(int x);
    void hide_2(float x);
};

#endif // BASE_H
