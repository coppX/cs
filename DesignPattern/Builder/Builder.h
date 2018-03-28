#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <string>
#include <vector>

using namespace std;

class Product
{
private:
	string m_partA;
	string m_partB;
	string m_partC;
public:
	void setPartA(const string& s);
	void setPartB(const string& s);
	void setPartC(const string& s);
	Product();
	~Product();
};

class Builder{
public:
	virtual void BuildPartA() {}
	virtual void BuildPartB() {}
	virtual void BuildPartC() {}
	virtual Product* GetProduct(){}
	Builder();
	virtual ~Builder();
};

class ConcreteBuilder1:public Builder
{
public:
	ConcreteBuilder1();
	~ConcreteBuilder1();
	virtual void BuildPartA();
	virtual void BuildPartB();
	virtual void BuildPartC();
	virtual Product* GetProduct();
private:
	Product* m_pProduct;
};

class ConcreteBuilder2:public Builder
{
public:
	ConcreteBuilder2();
	~ConcreteBuilder2();
	virtual void BuildPartA();
	virtual void BuildPartB();
	virtual void BuildPartC();
	virtual Product* GetProduct();
private:
	Product* m_pProduct;
};

class Director
{
public:
	Director(Builder* pBuilder);
	~Director();
	void Construct();
private:
	Builder* m_pBuilder;
};

#endif
