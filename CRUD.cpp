#include <iostream>
#include "Header/CRUD.h"
#include "Header/User.h"
#include "Header/Menu.h"
using namespace std;

int main() {
    List *L1 = createEmptyList();
    int choice;

    mainMenu:
        cout << setw(25) << "Welcome To The Cafe" << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Buy Coffee" << endl;
        cout << "2. Staff Mangament" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1) {
            coffeeList();
            cout << endl;
            orderCoffee();
            goto mainMenu;
        }
        else if(choice == 2) {
            staffPanel();
            goto mainMenu;
        }
        else if(choice == 3) {
            return 0;
        }
        else {
            cout << "Wrong Input Try Again!" << endl;
            goto mainMenu;
        }
        
    return 0;
}