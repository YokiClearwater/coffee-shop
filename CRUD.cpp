#include <iostream>
#include <fstream>
#include <iomanip>
#include "CRUD.h"
#include "Menu.h"
using namespace std;

int main() {
    List *L1 = createEmptyList();
    int choice;

    mainMenu:
        cout << "1. Coffee List" << endl;
        cout << "2. Staff Mangament" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1) {
            coffeeList();
            goto mainMenu;
        }
        else if(choice == 2) {
            staffPanel();
            goto mainMenu;
        }
        else if(choice == 3) {
            exit(0);
        }
        else {
            cout << "Wrong Input Try Again!" << endl;
            goto mainMenu;
        }
        

    return 0;
}