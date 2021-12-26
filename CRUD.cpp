#include <iostream>
#include "Header/Console.h"
#include "Header/CRUD.h"
#include "Header/User.h"
#include "Header/Menu.h"
using namespace std;

int main() {
    List *L1 = createEmptyList();
    int choice;

    mainMenu:
        cout << "\n-------------------------------" << endl;
        cout << setw(25) << "Welcome To The Cafe" << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Buy Coffee" << endl;
        cout << "2. Staff Mangament" << endl;
        cout << "3. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1) {
            clearScreen();
            coffeeList();
            cout << endl;
            orderCoffee();
            clearScreen();
            goto mainMenu;
        }
        else if(choice == 2) {
            clearScreen();
            staffPanel();
            clearScreen();
            goto mainMenu;
        }
        else if(choice == 3) {
            return 0;
        }
        else {
            clearScreen();
            cout << "Wrong Input Try Again!" << endl;
            sleepTime(1000);
            clearScreen();
            goto mainMenu;
        }
        
    return 0;
}