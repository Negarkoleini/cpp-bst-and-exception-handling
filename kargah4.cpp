#include <iostream>
#include"array.h"

using namespace std;

int main()
{
		FixedArray<int> arr1(20);
		for (int i = 0; i < 20; i++)
			arr1[i] = i * 10;

		arr1.print(); // 0, 10, 20, ...
		cout << arr1[0] << endl; // 0


	try {

		cout << arr1[-1]; // exception!
	}
	catch (const out_of_range& e) {
		cerr << "Index Error: " << e.what() << endl;
	}

	catch (const runtime_error& e) {
		cerr << "Index not true: " << e.what() << endl;
	}

	try{
		arr1[20] = 5; // exception!

	}
	catch (const out_of_range& e) {
		cerr << "Index Error: " << e.what() << endl;
	}

	catch (const runtime_error& e) {
		cerr << "Index not true: " << e.what() << endl;
	}
		FixedArray<int> arr2(10);
		for (int i = 0; i < 10; i++)
			arr2[i] = i * 2;

	try{


		arr2 = arr1; // exception!
	}
	catch (const out_of_range& e) {
		cerr << "Index Error: " << e.what() << endl;
	}

	catch (const runtime_error& e) {
		cerr << "Index not true: " << e.what() << endl;
	}
		arr2.print();// 0, 2, 4, 6, ...
		arr1 = arr2;
		arr1.fill(2, 5, 0);
		arr1.print(); // 0, 2, 0, 0, 0, 10, 12, 14, 16, 18, 100, 110 ...


	try {
		arr1.fill(5, 25, 2); // exception!

	}

	catch (const out_of_range& e) {
		cerr << "Index Error: " << e.what() << endl;
	}

	catch (const runtime_error& e) {
		cerr << "Index not true: " << e.what() << endl;
	}

}