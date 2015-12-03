#ifndef SINGULARCALLBACK_H
#define SINGULARCALLBACK_H


template < class Class, typename ReturnType, typename Parameter >
class SingularCallBack
{

   public:

    typedef ReturnType (Class::*Method)(Parameter);

    //函数的指针,作为地址传递给这个构造函数,当函数指针被调用它只想的函数就是回调函数.
    SingularCallBack(Class* _class_instance, Method _method)
    {
       //取得对象实例地址,及调用方法地址
       class_instance = _class_instance;
       method        = _method;
    };

    ReturnType operator()(Parameter parameter)
    {
       // 调用对象方法
       return (class_instance->*method)(parameter);
    };

    ReturnType execute(Parameter parameter)
    {
       // 调用对象方法
       return operator()(parameter);
    };


   private:

    Class*  class_instance;
    Method  method;

};

#endif // SINGULARCALLBACK_H
