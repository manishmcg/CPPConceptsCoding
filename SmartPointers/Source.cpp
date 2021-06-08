#include <iostream>
#include "my_smart_pointer.h"
using namespace std;

class smart_pointer
{
public:
	explicit smart_pointer(int* p = nullptr)
	{
		data = p;
	}
	~smart_pointer() {
		cout << "Deleting data" << endl;
		delete data;
	}
	int& operator* () 
	{
		return *data;
	}

private:
	int* data;
};

class Foo
{
public:
	explicit Foo(int x) : x(x) {}
	int getX() { return x; }
	void setX(int x) { this->x = x; }
	~Foo() { cout << "Dest Foo"<<endl; }

private:
	int x;
};

int main()
{
	cout << "class smart_pointer, I have declared and Define in Main File" << endl;
	{
		int* p = new int(10);
		smart_pointer myint = smart_pointer(p);
		cout << *myint << endl;
	}
	/*
	{
		int* q = new int(20);
		my_smart_pointer my_int = my_smart_pointer(q);
		cout << *my_int << endl;
	}*/

	cout << "\n\nclass my_smart_pointer, I have declared and Define in New class/header File" << endl;
	{
		double* r = new double(20);
		my_smart_pointer my_int = my_smart_pointer(r);
		cout << *my_int << endl;
	}


	cout << "\n\n\nunique_ptr: get, release, reset, swap, get_deleter" << endl;
	{
		unique_ptr<Foo> p1(new Foo(10)); // One way
		cout << p1->getX() <<" "<< (*p1).getX() << " Both are same" << endl;
		//Foo* p7 = p1; // not allowed
		unique_ptr<Foo> p2 = make_unique<Foo>(20); // another way
		//p2 = p1; // not allowed
		unique_ptr<Foo> p3 = std::move(p1); // moving ownership of p1 to p3
		cout <<"p3:  " << p3->getX() << endl;
		//cout << "p1:  " << p1->getX() << endl; // undefine behavior as pointer deallocated;
		Foo* p4 = p3.get();
		p4->setX(60);
		cout << "p4:  " << p4->getX() << endl;
		cout << "p33:  " << p3->getX() << endl;
		Foo* p5 = p3.release();
		cout << "After release to p5: p5:  " << p5->getX() << endl;
		//cout << "p333:  " << p3->getX() << endl;// undefine behavior as ownership released to p5;
		unique_ptr<Foo> p6 = make_unique<Foo>(30); // another way
		p6.swap(p2);
		cout << "After swap: p2:  " << p2->getX() << " " << "p6:  " << p6->getX() << endl;
		p6.reset();
		//cout << "After reset:  p6:  " << p6->getX() << endl;// undefine behavior as pointer deallocated;

	}

	return 0;
}