#pragma once


#include<iostream>
#include<string>
#include <stdexcept>

using namespace std;

template<typename T>
class FixedArray {

private:
	int size;
	T* data;

public:

	FixedArray(int s) :size(s) {
		data = new T[size];

		for (int i = 0; i < s; ++i)
			data[i] = 0;

	}


	~FixedArray() {
		delete[] data; 
		data = nullptr;
	}

	T& operator []( int index ) {
		if (index < 0 || index >= size )
			throw out_of_range("index is not true");

		return data[index];
	}

	const T& operator [](int index) const {
		if (index < 0 || index >= size)
			throw out_of_range("index is not true");

		return data[index];
	}

//	FixedArray(const FixedArray& other) {
//		this->size = other.size ;
//		this->data = new T[size];
//
//		for (int i = 0; i < size; ++i)
//			data[i] = other.data[i];
//
//	}

	FixedArray& operator=(const FixedArray& other) {
		if (size < other.size)
			throw runtime_error("Target array size is smaller than source array");


		delete[] data;
		size = other.size;
		data = new T[size];

		for (int i = 0; i < size; ++i)
			this->data[i] = other.data[i];

		return *this;
	}

	void fill(int start, int end, T value) {
	     if (start < 0 || start >= size  || end < 0 || end >= size) 
			throw out_of_range("Start or End index is out of bounds.");


		for (int i = start; i <= end; ++i)
			data[i] = value;

	}

	void print() {
		for (int i = 0; i < size; ++i)
			cout << data[i] << " ";

		cout << endl;
	}



 };
