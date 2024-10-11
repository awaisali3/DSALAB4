#include "Node.h"

class HList {
private:
    Node* head;  // Dummy head node

public:
    HList();  // Constructor to initialize the list with a dummy head
    bool emptyList();  // Checks if the list is empty
    void insert_after(int oldV, int newV);  // Inserts new node after node with value oldV
    void insert_begin(int value);  // Inserts new node at the start of the list
    void insert_end(int value);  // Inserts new node at the end of the list
    void delete_Node(int val);  // Deletes node with value val
    void delete_begin();  // Deletes node from the beginning
    void delete_end();  // Deletes node from the end
    void traverse();  // Displays all values in the list
};
