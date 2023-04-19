#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

void insertAfter(vector<int>& vec, int firstValue, int secondValue) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == firstValue) {   // check if the current element has the first value
            vec.insert(vec.begin() + i + 1, secondValue);    // insert the second value after the current element
            i++;    // skip the newly inserted element
        }
    }
}

LinkedList createLinkedList(vector<int>& vec) {
    LinkedList list;
    for (int i = 0; i < vec.size(); i++) {
        int count = 1;
        for (int j = i + 1; j < vec.size(); j++) { // loop through the remaining elements in the vector
            if (vec[i] == vec[j]) { // if the value at index i is equal to the value at index j
                count++; // increment the count
                vec.erase(vec.begin() + j); // remove the duplicate element from the vector
                j--; // decrement j to account for the removed element
            }
        }
        list.add(vec[i], count); // add the value and its count to the linked list
    }
    return list; // return the linked list
}

int main() {
    int n, first, second, remove;

    // create the vector first
    cout << "Please enter the number of elements in the vector: ";
    cin >> n;
    vector<int> v(n);

    // fill up the vector
    cout << "Please enter the numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // search and insert in the vector
    cout << "Please enter the first value to search for: ";
    cin >> first;
    cout << "Please enter the second value to insert: ";
    cin >> second;
    insertAfter(v, first, second); // call the insertAfter function

    // create a linked list with the vector
    LinkedList list = createLinkedList(v); // create the linked list
    cout << "Here is the list of the numbers you entered: ";
    list.print();
    cout << "The sum of all the nodes in the list: " << list.sum() << endl; // print the sum of all nodes in the linked list

    // remove a value and print the linked list
    cout << "Please enter the value to remove: ";
    cin >> remove;
    list.remove(remove); // remove a node with the given value from the linked list
    cout << "The updated list after removing " << remove << ": ";
    list.print(); // print the updated linked list

    return 0;
}
