#include <iostream>
#include "List.h"

using namespace std;

// Constructor: Initializes list with a dummy head node
HList::HList() {
    head = new Node(-1);  // Dummy head node, -1 can be any value that won't be in the list
}

// Check if the list is empty (i.e., no real nodes)
bool HList::emptyList() {
    return head->next == nullptr;  // Empty if dummy head points to nothing
}

// Insert new node with value newV after the node with value oldV
void HList::insert_after(int oldV, int newV) {
    Node* temp = head->next;  // Start after dummy head
    while (temp != nullptr) {
        if (temp->data == oldV) {
            Node* newNode = new Node(newV);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
    cout << "Value " << oldV << " not found in the list!" << endl;
}

// Insert a new node at the beginning (right after dummy head)
void HList::insert_begin(int value) {
    Node* newNode = new Node(value);
    newNode->next = head->next;
    head->next = newNode;
}

// Insert a new node at the end of the list
void HList::insert_end(int value) {
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Node* newNode = new Node(value);
    temp->next = newNode;
}

// Delete a node with the value val
void HList::delete_Node(int val) {
    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == val) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
        }
        temp = temp->next;
    }
    cout << "Value " << val << " not found in the list!" << endl;
}

// Delete the first node (after the dummy head)
void HList::delete_begin() {
    if (emptyList()) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* toDelete = head->next;
    head->next = toDelete->next;
    delete toDelete;
}

// Delete the last node in the list
void HList::delete_end() {
    if (emptyList()) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->next != nullptr) {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = nullptr;
    delete toDelete;
}

// Display all values in the list (except the dummy head)
void HList::traverse() {
    Node* temp = head->next;
    if (emptyList()) {
        cout << "List is empty!" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
