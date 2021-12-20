#include <iostream>
#include <fstream>
#include <iomanip>
#include "CRUD.h"
#include "Menu.h"
using namespace std;

int main() {
    List *L1 = createEmptyList();
    int choice;

    insertBegin(L1, "1", "Latte", "123.5");
    insertBegin(L1, "2", "Americano", "123.5");
    insertBegin(L1, "3", "Ice-Cream", "123.5");
    insertEnd(L1, "5", "Bread", "15.5");

    do {
        cout << "1. Coffee List" << endl;
        cout << "2. Staff Mangament" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1) {
            coffeeList();
        }
        else if(choice == 3) {
            break;
        }
        else {
            cout << "Wrong Input Try Again!" << endl;
        }
        
    } while(choice != 3);

    return 0;
}