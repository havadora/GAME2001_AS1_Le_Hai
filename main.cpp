#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	int size = 5;
	UnorderArray<int> array(1);
	OrderArray<int> array1(size);
	//array.setSize(3);
	cout << "Unorder Array" << endl;
	array.push(5);
	array1.push(4);
	array1.push(43);
	array1.push(2);
	array1.push(44);
	
	//array1.sorting();
	array.print();
	cout << endl;
	cout << "Order Array" << endl;
	array1.push(4);
	array1.push(43);
	array1.push(2);
	array1.push(44);
	array1.push(20);
	array1.push(18);
	//array1.sorting();
	
	array1.sorting();
	array1.print();
	
	
    system("pause");
	return 0;
};