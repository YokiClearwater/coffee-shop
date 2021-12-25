void coffeeList() {
    List *ls = readFile();
    cout << "ID" << setw(15) << "Name" << setw(15) << "Price" << endl;
    cout << "---------------------------------" << endl;
    displayList(ls);
}

void bestBuy();
void orderCoffee();
void viewUser();
void clear();

void staffPanel() {
    int choice;
    List *L1 = readFile();
    string id, name, price;

    adminPanel:
        cout << setw(25) << "Administrator Panel" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Create Item" << endl;
        cout << "2. Read Item" << endl;
        cout << "3. Update Item" << endl;
        cout << "4. Delete Item" << endl;
        cout << "5. Best Custormer" << endl;
        cout << "6. View Customer Purchase List" << endl; 
        cout << "7. Back to Main Menu" << endl;
        cout << "---------------------------------" << endl;
        cout << "Input Choice: ";
        cin >> choice;

        if(choice == 1) {
            system("CLS");
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter Item Name: ";
            cin >> name;
            cout << "Enter Item Price: ";
            cin >> price;
            insertEnd(L1, id, name, price);
            writeFile(L1);
            Sleep(200);
            system("CLS");
            goto adminPanel;
        }
        else if(choice == 2) {
            system("CLS");
            coffeeList();
            Sleep(7000);
            system("CLS");
            goto adminPanel;
        }
        else if(choice == 3) {
            system("CLS");
            cout << "Enter ID to Search: ";
            cin >> id;
            updateItem(L1, id);
            writeFile(L1);
            system("CLS");
            goto adminPanel;
        }
        else if(choice == 4) {
            system("CLS");
            cout << "Enter ID: ";
            cin >> id;
            deleteItem(L1, id);
            writeFile(L1);
            system("CLS");
            goto adminPanel;
        }
        else if(choice == 5) {
            system("CLS");
            bestBuy();
            Sleep(5000);
            system("CLS");
            goto adminPanel;
        }
        else if(choice == 6) {
            system("CLS");
            viewUser();
            Sleep(7000);
            system("CLS");
            goto adminPanel;
        }
        else if(choice == 7) {
            system("CLS");
            return;
        }
        else {
            cout << "Wrong Input!!" << endl;
            goto adminPanel;
        }
}

void orderCoffee() {
    int choice;

    coffeeShop:
        cout << "Do you want to buy some coffee?" << endl;
        cout << "1. Buy Some Coffee" << endl;
        cout << "2. Back to Main Menu" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if(choice == 1) {
            UserList *U1 = readUserFile();
            buyCoffee(U1);
            writeUserFile(U1);
        }
        else if(choice == 2) {
            return;
        }
        else {
            cout << "Wrong Input!!" << endl;
            goto coffeeShop;
        }
}

void bestBuy() {
    UserList *ul = readUserFile();
    User *bestUser = bestCustomer(ul);
    cout << "Our Best Customer is " << bestUser->name << " spending $ " << bestUser->payment << endl;
}

void viewUser() {
    UserList *ul = readUserFile();
    cout << "Display Customer List" << endl;
    cout << "Coffee ID" << setw(7) << "Name" << setw(12) << "Quantity" << setw(10) << "Payment" << endl; 
    cout << "--------------------------------------" << endl;
    displayUser(ul);
}
