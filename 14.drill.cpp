#include "std_lib_facilities.h"

class B1{
public:
	void f() { cout << "B1::f()" << endl; }
	virtual void vf() { cout << "B1::vf()" << endl; }
	virtual void pvf() =0; 
};

class D1 : public B1{
public:
	void vf() override { cout << "D1::vf()" << endl; }
	void f() { cout << "D1::f()" << endl; }
};

class D2 : public D1{
public:
	void pvf() override { cout << "D2::pvf()" << endl; }
};

class B2{
public:
	virtual void pvf() =0;
};

class D21 : public B2{
public:
	string x = "string";

	void pvf() override { cout << x << endl; }
};

class D22 : public B2{
public:
	int y = 22;

	virtual void pvf() override { cout << y << endl; };
};

void f(B2& b){
	b.pvf();
}

int main()
{
	/*
	B1 b;
	b.vf();
	b.f();

	D1 d;
	d.vf();
	d.f();

	D2 dd;
	dd.f();
	dd.vf();
	dd.pvf();
	*/

	D21 dd1;
	D22 dd2;

	f(dd1);
	f(dd2);
}