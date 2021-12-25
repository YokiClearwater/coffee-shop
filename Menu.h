void coffeeList() {
    List *ls = readFile();
    cout << "ID" << setw(15) << "Name" << setw(15) << "Price" << endl;
    displayList(ls);
}

void staffPanel() {
    int choice;
    List *L1 = readFile();
    string id, name, price;

    adminPanel:
        cout << "1. Create Item" << endl;
        cout << "2. Read Item" << endl;
        cout << "3. Update Item" << endl;
        cout << "4. Delete Item" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Input Choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter Item Name: ";
            cin >> name;
            cout << "Enter Item Price: ";
            cin >> price;
            insertEnd(L1, id, name, price);
            writeFile(L1);
            goto adminPanel;
        }
        else if(choice == 2) {
            coffeeList();
            goto adminPanel;
        }
        else if(choice == 3) {
            cout << "Enter ID to Search: ";
            cin >> id;
            updateItem(L1, id);
            writeFile(L1);
            goto adminPanel;
        }
        else if(choice == 4) {
            cout << "Enter ID: ";
            cin >> id;
            deleteItem(L1, id);
            writeFile(L1);
            goto adminPanel;
        }
        else if(choice != 5 && choice >= 4) {
            cout << "Wrong Input!!" << endl;
            goto adminPanel;
        }
}

void userPurchase() {
    
}