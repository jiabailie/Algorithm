#include <cstdio>
#include <iostream>
#define VIRTUAL
#undef  VIRTUAL

using namespace std;

class C
{
public:
	C() { std::cout << "C build" << std::endl; }
	~C() { std::cout << "C destroy" << std::endl; }
};

class A
{
public:
	A() { std::cout << "A build" << std::endl; }
#ifdef VIRTUAL
	virtual ~A() { std::cout << "A destroy" << std::endl; }
#else
	~A() { std::cout << "A destroy" << std::endl; }
#endif
private:
	C c;
};

class B : public A
{
public:
	B() { std::cout << "B build" << std::endl; }
	~B() { std::cout << "B destroy" << std::endl; }
private:
	C c;
};

int main()
{
	cout << "B b" << endl;
	B b;
	cout << endl << endl;

	cout << "A *pa = new B()" << endl;
	A *pa = new B();
	delete pa;
	cout << endl << endl;

	cout << "B *pb = static_cast<B*>(new A());" << endl;
	B *pb = static_cast<B*>(new A());
	delete pb;
	cout << endl << endl;

	return 0;
}