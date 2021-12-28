#include <iostream>
#include <conio.h>
#include "Header/Console.h"
#include "Header/CRUD.h"
#include "Header/Login.h"
#include "Header/User.h"
#include "Header/Menu.h"

using namespace std;

int main() {
    int choice;

    loginMenu:
        cout << "\n-------------------------------" << endl;
        cout << setw(25) << "Welcome To User Menu" << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Login" << endl;
        cout << "2. Sign Up" << endl;
        cout << "3. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Login Menu:" << endl;
            UserLogin *U1 = logIn();
            cout << "You are login as " << U1->userName << endl;
            mainMenu(U1);
            goto loginMenu;
        }
        else if(choice == 2) {
            cout << "Sign Up Menu: " << endl;
            signUp();
            goto loginMenu;
        }
        else if(choice == 3) {
            return 0;
        }
        else {
            cout << "Wrong Choice!!" << endl;
            goto loginMenu;
        }
    
    return 0;
}