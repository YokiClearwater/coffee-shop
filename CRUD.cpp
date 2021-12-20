#include <iostream>
#include <fstream>
#include "CRUD.h"
using namespace std;

int main() {
    List *L1 = createEmptyList();

    insertBegin(L1, "1", "Latte", "123.5");
    insertBegin(L1, "2", "Americano", "123.5");
    insertBegin(L1, "3", "Ice-Cream", "123.5");
    insertEnd(L1, "4", "Bread", "15.5");


    displayList(L1);

    // updateItem(L1, "2");

    deleteItem(L1, "2");

    displayList(L1);
    
    // displayReverseList(L1);

    // writeFile(L1);

    // List *L2 = readFile(); // Text File Shouldn't have a space

    // displayList(L2);

    return 0;
}