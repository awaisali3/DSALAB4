#include <iostream>
#include "CList.h"

using namespace std;

int main() {
    CList list;

    // Inserting values into the circular linked list
    list.insert_end(10);
    list.insert_end(20);
    list.insert_end(30);
    list.insert_begin(5);

    // Display the list
    cout << "Circular list: ";
    list.traverse();

    // Inserting a node at a specific position
    list.insert_at(3, 15);

    // Display after inserting at position 3
    cout << "After inserting at position 3: ";
    list.traverse();

    // Delete the first node
    list.delete_begin();
    cout << "After deleting the first node: ";
    list.traverse();

    // Delete the last node
    list.delete_end();
    cout << "After deleting the last node: ";
    list.traverse();

    // Delete a node at a specific position
    list.deleteNode(2);
    cout << "After deleting node at position 2: ";
    list.traverse();

    return 0;
}
