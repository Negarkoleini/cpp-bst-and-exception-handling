#include <iostream>
#include "BST.h"
#include<execution>

using namespace std;

int main()
{
        BST<int> bst;
        
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(1);
        bst.insert(4);
        
        bst.inorder(); // output: 1 3 4 5 7
    try {
        
        bst.insert(3); // exception: Duplicate value
        
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    try {
        bst.find(10); // exception: Value not found
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    
    try {
        bst.remove(3); // exception: Cannot remove non-leaf node
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }
        
        bst.remove(4);
        
        bst.inorder(); // output: 1 3 5 7
}
