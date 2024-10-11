// List.h
#include "Node.h"

class List {
private:
    Node* head;  // Pointer to the dummy header node

public:
    List();      // Constructor
    ~List();     // Destructor

    void insert(int value);  // Method to insert a value
    void display();          // Method to display the list
};
