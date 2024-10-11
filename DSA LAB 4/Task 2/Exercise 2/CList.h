#include "Node.h"

class CList {
private:
    Node* head;  // Points to the last node in the list

public:
    CList();  // Constructor to initialize an empty circular linked list
    bool emptyList();  // Checks if the list is empty
    void insert_at(int pos, int value);  // Inserts a node at position `pos` (excluding pos=1)
    void insert_begin(int value);  // Inserts a node at the start of the list
    void insert_end(int value);  // Inserts a node at the end of the list
    void deleteNode(int pos);  // Deletes a node at position `pos` (excluding the first node)
    void delete_begin();  // Deletes the first node in the list
    void delete_end();  // Deletes the last node in the list
    void traverse();  // Displays the values in the circular list
};
