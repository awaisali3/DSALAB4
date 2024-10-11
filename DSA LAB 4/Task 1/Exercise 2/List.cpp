// List.cpp
#include <iostream>
#include "List.h"

using namespace std;

// Constructor: Initialize an empty circular linked list
List::List() {
    last = nullptr;  // Start with an empty list
}

// Destructor: Free all nodes
List::~List() {
    if (!last) return;  // If the list is empty, no need to delete

    Node* temp = last->next;
    last->next = nullptr;  // Break circular link to stop the loop

    // Delete all nodes
    while (temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

// Insert a new node at the end of the circular list
void List::insert(char c) {
    Node* newNode = new Node(c);

    if (!last) {  // If the list is empty, create a self-loop
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;  // Insert the new node after the last node
        last->next = newNode;
        last = newNode;  // Update the last node
    }
}

// Merge this circular list with another one
void List::merge(List &list2) {
    if (!last || !list2.last) return;  // If either list is empty, do nothing

    // Point the last node of this list to the first node of list2
    Node* first1 = last->next;         // First node of list1
    Node* first2 = list2.last->next;   // First node of list2
    
    last->next = first2;               // Connect last of list1 to first of list2
    list2.last->next = first1;         // Connect last of list2 to first of list1

    last = list2.last;  // Update this list's last to the last of list2
}

// Display the circular linked list
void List::display() {
    if (!last) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = last->next;  // Start from the node after the last node (first node)
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);  // Stop when we loop back to the start

    cout << endl;
}
