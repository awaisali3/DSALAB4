// List.h
#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
private:
    Node* last;  // Pointer to the last node in the circular list

public:
    List();                // Constructor to initialize an empty list
    ~List();               // Destructor to free memory
    void insert(char c);   // Method to insert a character into the circular list
    void merge(List &list2); // Merge another circular list into this one
    void display();        // Method to display the contents of the circular list
};

#endif
