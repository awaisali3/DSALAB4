// main.cpp
#include "List.h"

using namespace std;

int main() {
    List myList;

    // Insert some elements
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);

    // Display the list
    cout << "Elements in the list: ";
    myList.display();

    return 0;
}
