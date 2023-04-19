//
// Created by Adam on 4/14/2023.
//
#include <iostream>
using namespace std;
#ifndef ASSIGNMENT4_LINKEDLIST_H
#define ASSIGNMENT4_LINKEDLIST_H

struct Node {
    int value, count;
    Node* next;     // points to the next node in the list

    Node(int v, int c) {
        count = c;
        value = v;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;  // points to the first node in the list
public:
    LinkedList() {
        head = NULL;
    }

    void add(int value, int count = 1) {  // the count is by default equal to 1
        Node* node = new Node(value, count);
        node->next = head;
        head = node;
    }

    void remove(int value) { // Remove the first node in the list with the given value.
        Node* one = NULL;
        Node* two = head;
        while (two != NULL) {  // Go over the list
            if (two->value == value) { // check if the value is in the two node
                if (one == NULL) // if the node is the first in the list
                    head = two->next;  // the head becomes the next node
                else // if the is not the first in the list
                    one->next = two->next;  // link the one node to the next node
                delete two;    // delete the node
                return;
            }
            one = two;    // move to the next node
            two = two->next;
        }
    }

    int sum() {
        int sum = 0;  // initialize the sum to 0
        Node* node = head;
        while (node != NULL) {
            sum += (node->value) * (node->count); // add the value as many times as it occurs to the sum
            node = node->next;  // switch to next node
        }
        return sum;
    }

    void print() {
        Node* node = head;
        while (node != NULL) {
            cout << node->value << " with count " << node->count << " ---> "; // print the value and count
            node = node->next;  // move to the next node
        }
        cout << "NULL" << endl;
    }
};


#endif //ASSIGNMENT4_LINKEDLIST_H
