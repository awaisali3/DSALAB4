#include <iostream>
#include "List.h"

using namespace std;

int main() {
    HList list;

    // Insert values into the list
    list.insert_end(10);
    list.insert_end(20);
    list.insert_end(30);
    list.insert_begin(5);
    list.insert_after(20, 25);

    // Display the list
    cout << "Current list: ";
    list.traverse();

    // Delete nodes
    list.delete_begin();
    list.delete_end();
    list.delete_Node(25);

    // Display the list after deletions
    cout << "List after deletions: ";
    list.traverse();

    return 0;
}
