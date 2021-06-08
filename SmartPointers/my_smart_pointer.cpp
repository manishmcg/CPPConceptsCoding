#include<iostream>
#include "my_smart_pointer.h"

//my_smart_pointer::my_smart_pointer(int* p = nullptr)
//{
//	data = p;
//}
my_smart_pointer::my_smart_pointer(double* p = nullptr)
{
	data = p;
}

my_smart_pointer::~my_smart_pointer()
{
	std::cout << "Deleting data" << std::endl;
	delete data;
}

double& my_smart_pointer:: operator* ()
{
	return *data;
}