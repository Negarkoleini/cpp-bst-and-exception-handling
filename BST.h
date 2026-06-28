#pragma once

#include<iostream>
#include<string>
#include <exception>

using namespace std;

template<typename T>
class BST : public exception {

private:
	struct Node {
		T data;
		Node* down;  
		Node* up; 

		Node(T val) : data(val), down(nullptr), up(nullptr) {}
	};
	Node* root = nullptr;

public:

	void insert(const T& value) {
		Node* newnode = new Node(value);

		if (root == nullptr) {
			root = newnode;
			return;
		}

		Node* htemp = root;
		Node* prev = nullptr;
		int flag = 0;

		while (htemp != nullptr) {
			if (value < htemp->data) {
				prev = htemp;
				htemp = htemp->down;
				flag = 0;
			}
			else if (value > htemp->data) {
				prev = htemp;
				htemp = htemp->up;
				flag = 1;
			}
			else {
				throw runtime_error("value is already available");
			}
		}

		if (flag)
			prev->up = newnode;
		else
			prev->down = newnode;

	}

	const T* find(const T& value) const {
		Node* temp = root;
		while (temp != nullptr) {
			if (temp->data == value)
				return &(temp->data);

			else if (temp->data > value)
				temp = temp->down;

			else
				temp = temp->up;

		}

		throw runtime_error("coulden't find data");

	}
	void print(Node* main) {
		while (main != nullptr) {
			main = main->down;
			print(main);
		}

		cout << main->data << " ";

		if(main->up != nullptr)
			cout << main->up->data << " ";

	}

	void inorder(Node* Root) const{

		if (Root == nullptr) 
			return;


		inorder(Root->down);
		
		cout << Root->data << " ";

		inorder(Root->up);


	}


	void inorder() const {

		inorder(root);

		cout << endl;

	}
	void remove(const T& value) {
		Node* temp = root;
		Node* prev = nullptr;
		int flag = 0;
		int tick = 0;

		while (temp != nullptr) {
			if (temp->data == value) {
				flag = 1;
				if (temp->up == nullptr && temp->down == nullptr) {
					if (tick== 2)
						prev->down = nullptr;
					else if (tick == 3)
						prev->up = nullptr;

					delete(temp);
					break;
				}

				else
					throw runtime_error("we can't delete this data");
			}
			else if (temp->data > value) {
				tick = 2;
				prev = temp;
				temp = temp->down;
			}

			else if (temp->data < value) {
				tick = 3;
				prev = temp;
				temp = temp->up;
			}

		}

		if(flag == 0)
			throw runtime_error("data not found");
	}

};
