// TestUmlClass.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Product
{
public:
	Product(){};
	virtual ~Product(){};
	  

};
class AProduct :public Product
{
public:
	AProduct(){cout<<"AProduct";};
	virtual ~AProduct(){};
};
class BProduct :public Product
{
public:
	BProduct(){cout<<"BProduct";};
	virtual ~BProduct(){};
};

class Factory
{
public:
	Factory(){};
	virtual ~Factory(){};

	virtual Product * getProduct()=0;
};

class AFactory :public Factory
{
public:
	AFactory(){};
	virtual ~AFactory(){};

	 Product * getProduct()
	{
		 return (new AProduct());
	}
};

class BFactory :public Factory
{
public:
	BFactory(){};
	virtual ~BFactory(){};

	 Product * getProduct()
	{
		return (new BProduct());
	}
};





int _tmain(int argc, _TCHAR* argv[])
{
	Factory * _fac=new AFactory();
	_fac->getProduct();

	getchar();

	return 0;
}

