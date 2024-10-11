// List.cpp
#include <iostream>
#include "List.h"

using namespace std;

// Constructor: Creates a dummy node and initializes the list
List::List() {
    head = new Node();  // Dummy node with default value 0
    head->next = nullptr;
}

// Destructor: Deletes all nodes, including the dummy header
List::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Insert: Adds a new node at the end of the list
void List::insert(int value) {
    Node* newNode = new Node(value);  // Create a new node
    Node* temp = head;                // Start at the dummy node

    // Traverse to the end of the list
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Insert new node at the end
    temp->next = newNode;
}

// Display: Outputs the data in the list
void List::display() {
    Node* temp = head->next;  // Skip the dummy node

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
