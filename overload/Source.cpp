#include "DynamicArray.h"
#include <iostream>
using namespace std;
int main()
{
	DynamicArray a(5); // constructor 1 param
	a.Input();
	a.Output();
	DynamicArray test1 = a + 2;
	test1.Output();
	DynamicArray test2 = a - 3;
	test2.Output();
	DynamicArray test3 = a * 2;
	test3.Output();
	DynamicArray test4 = a - test2;
	test4.Output();
	DynamicArray test5 = test2 - a;
	test5.Output();
	DynamicArray test6 = ++a;
	test6.Output();
	DynamicArray test7 = --a;
	test7.Output();



	system("pause");
}