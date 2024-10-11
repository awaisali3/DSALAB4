// main.cpp
#include <iostream>
#include "List.h"

using namespace std;

int main() {
    // Create the first circular list: "POWER"
    List list1;
    list1.insert('P');
    list1.insert('O');
    list1.insert('W');
    list1.insert('E');
    list1.insert('R');

    // Create the second circular list: "POINT"
    List list2;
    list2.insert('P');
    list2.insert('O');
    list2.insert('I');
    list2.insert('N');
    list2.insert('T');

    // Display both lists before merging
    cout << "List 1 (before merge): ";
    list1.display();
    
    cout << "List 2 (before merge): ";
    list2.display();

    // Merge list1 and list2 into a single circular list
    list1.merge(list2);

    // Display the merged list
    cout << "Merged list: ";
    list1.display();

    return 0;
}
