#include <iostream>
#include "CList.h"

using namespace std;

// Constructor: Initializes an empty circular linked list
CList::CList() {
    head = nullptr;  // List is initially empty
}

// Check if the circular list is empty
bool CList::emptyList() {
    return head == nullptr;
}

// Insert a new node at a specific position `pos` (restrict pos=1)
void CList::insert_at(int pos, int value) {
    if (pos == 1) {
        cout << "Position 1 is restricted. Use insert_begin() for inserting at the start." << endl;
        return;
    }

    if (emptyList()) {
        cout << "The list is empty. Inserting at any position is not allowed. Use insert_begin() or insert_end() instead." << endl;
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head->next;  // Start from the first node
    int count = 2;

    // Traverse the list until the desired position is reached or the end of the list is found
    while (count < pos && temp != head) {
        temp = temp->next;
        count++;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;

    // If inserted at the end, update the head to point to the new last node
    if (temp == head) {
        head = newNode;
    }
}

// Insert a new node at the beginning
void CList::insert_begin(int value) {
    Node* newNode = new Node(value);

    if (emptyList()) {
        // For an empty list, the new node points to itself
        head = newNode;
        newNode->next = newNode;
    } else {
        // Insert new node after head and adjust the circular reference
        newNode->next = head->next;
        head->next = newNode;
    }
}

// Insert a new node at the end of the list
void CList::insert_end(int value) {
    Node* newNode = new Node(value);

    if (emptyList()) {
        // If the list is empty, the new node points to itself
        head = newNode;
        newNode->next = newNode;
    } else {
        // Insert new node after head and make it the last node
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;  // Update the head to the new last node
    }
}

// Delete a node at position `pos` (excluding the first node)
void CList::deleteNode(int pos) {
    if (pos == 1) {
        cout << "Cannot delete the first node with this function. Use delete_begin() instead." << endl;
        return;
    }

    if (emptyList()) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* temp = head->next;  // Start from the first node
    int count = 2;

    // Traverse the list until the node before the position is reached
    while (count < pos && temp->next != head->next) {
        temp = temp->next;
        count++;
    }

    if (count == pos) {
        // Delete the node at position `pos`
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        if (toDelete == head) {
            head = temp;  // Update head if the last node is deleted
        }
        delete toDelete;
    } else {
        cout << "Position out of bounds." << endl;
    }
}

// Delete the first node in the list
void CList::delete_begin() {
    if (emptyList()) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* firstNode = head->next;

    if (head == firstNode) {
        // Only one node in the list
        delete firstNode;
        head = nullptr;
    } else {
        head->next = firstNode->next;  // Bypass the first node
        delete firstNode;
    }
}

// Delete the last node in the list
void CList::delete_end() {
    if (emptyList()) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* temp = head->next;

    if (temp == head) {
        // Only one node in the list
        delete head;
        head = nullptr;
    } else {
        // Traverse to the second last node
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;  // Bypass the last node
        delete head;
        head = temp;  // Update head to the new last node
    }
}

// Display all values in the circular linked list
void CList::traverse() {
    if (emptyList()) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head->next;  // Start from the first node
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head->next);

    cout << endl;
}
