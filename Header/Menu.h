void coffeeList()
{
    List *ls = readFile();
    cout << "\n---------------------------------" << endl;
    cout << "ID" << setw(14) << "Name" << setw(16) << "Price" << endl;
    cout << "---------------------------------" << endl;
    displayList(ls);
}

void bestBuy();
void orderCoffee();
void viewUser();
void clear();
void totalEarning();
void deleteCoffeeMenu();


void staffPanel()
{
    int choice;
    List *L1 = readFile();
    string id, name, price;

    adminPanel:
        cout << "\n---------------------------------" << endl;
        cout << setw(25) << "Administrator Panel" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Create Item" << endl;
        cout << "2. Read Item" << endl;
        cout << "3. Update Item" << endl;
        cout << "4. Delete Item" << endl;
        cout << "5. Best Custormer" << endl;
        cout << "6. View Customer Purchase List" << endl;
        cout << "7. Total Earning" << endl;
        cout << "8. Delete All Coffee From Menu" << endl;
        cout << "9. Back to Main Menu" << endl;
        cout << "---------------------------------" << endl;
        cout << "Input Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            clearScreen();
            coffeeList();
            cout << "Adding New Cafe to Menu" << endl;
            cout << "---------------------------------" << endl;
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter Item Name: ";
            cin >> name;
            cout << "Enter Item Price: ";
            cin >> price;
            insertEnd(L1, id, name, price);
            writeFile(L1);
            clearScreen();
            goto adminPanel;
        }
        else if (choice == 2)
        {
            clearScreen();
            coffeeList();
            sleepTime(3000);
            goto adminPanel;
        }
        else if (choice == 3)
        {
            clearScreen();
            displayList(L1);
            cout << "Enter ID to Search: ";
            cin >> id;
            updateItem(L1, id);
            writeFile(L1);
            clearScreen();
            goto adminPanel;
        }
        else if (choice == 4)
        {
            clearScreen();
            displayList(L1);
            cout << "Enter ID: ";
            cin >> id;
            deleteItem(L1, id);
            writeFile(L1);
            clearScreen();
            goto adminPanel;
        }
        else if (choice == 5)
        {
            clearScreen();
            bestBuy();
            sleepTime(3000);
            goto adminPanel;
        }
        else if (choice == 6)
        {
            clearScreen();
            viewUser();
            sleepTime(3000);
            goto adminPanel;
        }
        else if (choice == 7)
        {
            clearScreen();
            totalEarning();
            sleepTime(3000);
            goto adminPanel;
        }
        else if (choice == 8) {
            clearScreen();
            deleteCoffeeMenu();
            clearScreen();
            goto adminPanel;
        }
        else if (choice == 9) {
            return;
        }
        else
        {
            clearScreen();
            cout << "Wrong Input!!" << endl;
            goto adminPanel;
        }
}

void orderCoffee()
{
    int choice;

    coffeeShop:
        cout << "Do you want to buy some coffee?" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Buy Some Coffee" << endl;
        cout << "2. Back to Main Menu" << endl;
        cout << "---------------------------------" << endl;
        cout << "\nEnter Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            UserList *U1 = readUserFile();
            buyCoffee(U1);
            writeUserFile(U1);
        }
        else if (choice == 2)
        {
            return;
        }
        else
        {
            cout << "Wrong Input!!" << endl;
            goto coffeeShop;
        }
}

void bestBuy()
{
    UserList *ul = readUserFile();
    UserList *U2 = sortUser(ul); 

    User *bestUser = bestCustomer(U2);
    cout << "\nOur Best Customer is " << bestUser->name << " spending $ " << bestUser->payment << endl;
}

void viewUser()
{
    UserList *ul = readUserFile();
    cout << "\nDisplay Customer List" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Coffee ID" << setw(8) << "Name" << setw(12) << "Quantity" << setw(13) << "Payment" << endl;
    cout << "--------------------------------------------" << endl;
    User *temp = ul->head;
    User *countIndex = ul->head;

    displayUser(ul);
}

void totalEarning() {
    UserList *U1 = readUserFile();
    User *temp = U1->head;
    float totalProfit;

    while(temp != NULL) {
        totalProfit += temp->payment;
        temp = temp->next;
    }
    cout << "\n--> Total Earning is $ " << totalProfit << endl;
}

void deleteCoffeeMenu() {
    List *L1 = readFile();
    deleteAllItem(L1);
    writeFile(L1);
}