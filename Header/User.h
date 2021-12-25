struct User {
    string itemID, name;
    int quantity;
    float payment;
    User *prev;
    User *next;
};

struct UserList {
    int n;
    User *head;
    User *tail;
};

UserList *createList() {
    UserList *ul = new UserList();
    ul->n = 0;
    ul->head = NULL;
    ul->tail = NULL;
    return ul;
}

void addUser(UserList *ul, string userName, string coffeeID, int coffeeCount, float price) {
    User *user = new User();
    user->itemID = coffeeID;
    user->name = userName;
    user->quantity = coffeeCount;  
    user->payment = price;
    user->prev = NULL;
    user->next = ul->head;

    if(ul->n == 0) {
        ul->tail = user;
    }

    if(ul->n != 0) {
        ul->head->prev = user;
    }
    ul->head = user;
    ul->n += 1;
}

void buyCoffee(UserList *U1) {
    List *ls = readFile();

    string coffeeID, userName;
    int quantity;
    float payment;

    cout << "Enter Your Name: ";
    cin >> userName;
    cout << "Enter Coffee ID: ";
    cin >> coffeeID;

    Coffee *item = searchItem(ls, coffeeID);
    while(item == NULL) {
        cout << "ID Not Found!! Enter Again: ";
        cin >> coffeeID;
    }

    cout << "Enter Quantity: ";
    cin >> quantity;  
    
    stringstream str(item->price);
    float price = 0;
    str >> price;

    payment = quantity*price;

    addUser(U1, userName, coffeeID, quantity, payment);
}

void displayUser(UserList *ul) {
    User *temp = ul->head;
    while(temp != NULL) {
        cout << temp->itemID << setw(15) << temp->name << setw(8) << temp->quantity << setw(15) << temp->payment << endl;
        temp = temp->next;
    }
    cout << endl;
}

User *bestCustomer(UserList *ul) {
    User *max, *temp;
    temp = max = ul->head;

    while(temp != NULL) {
        if(temp->name == max->name) {
            max->payment += temp->payment;
        }

        if(temp->payment > max->payment) {
            max = temp;
        }
        temp = temp->next;
    }

    return max;
}

void writeUserFile(UserList *ul) {
    ofstream file;
    file.open("CustomersList.txt", ios::app);

    User *temp = new User();
    temp = ul->head;
    while(temp != NULL) {
        file << temp->itemID << "\t" << temp->name << "\t" << temp->quantity << "\t" << temp->payment << endl;
        temp = temp->next;
    }

    file.close();
}

UserList *readUserFile() {
    ifstream file;
    file.open("CustomersList.txt");
    string userName, coffeeID, quantity, payment;
    int coffeeCount;
    float price;
    UserList *U2 = createList();

    while(file >> userName >> coffeeID >> quantity >> payment) {
        stringstream str(quantity), str2(payment);
        str >> coffeeCount;
        str2 >> price;
        addUser(U2, coffeeID, userName, coffeeCount, price);
    }

    file.close();
    return U2; 
}