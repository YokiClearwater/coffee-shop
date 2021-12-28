#include <fstream>
#include <iomanip>
using namespace std;

struct Coffee {
    string id, name;
    string price;
    Coffee *next;
    Coffee *prev;
};
struct List {
    int n;
    Coffee *head;
    Coffee *tail;
};

List *createEmptyList() {
    List *ls = new List();

    ls->n = 0;
    ls->head = NULL;
    ls->tail = NULL;

    return ls;
}

void insertBegin(List *ls, string itemID, string itemName, string itemPrice) {
    Coffee *item = new Coffee();
    item->id = itemID;
    item->name = itemName;  
    item->price = itemPrice;
    item->prev = NULL;
    item->next = ls->head;

    if(ls->n == 0) {
        ls->tail = item;
    }

    if(ls->n != 0) {
        ls->head->prev = item;
    }
    ls->head = item;
    ls->n += 1;
}

void insertEnd(List *ls, string itemID, string itemName, string itemPrice) {
    if(ls->n == 0) {
        insertBegin(ls, itemID, itemName, itemPrice);
    }
    else {
        Coffee *item = new Coffee();
        item->id = itemID;
        item->name = itemName;  
        item->price = itemPrice;
        item->next = NULL;
        item->prev = ls->tail;
        ls->tail->next = item;
        ls->tail = item;
        ls->n = ls->n + 1;

    }
}

Coffee *searchItem(List *ls, string itemID) {
    Coffee *temp = ls->head;
    int count = 0;

    while(temp != NULL) {
        count++;
        if(temp->id == itemID) {
            break;
        }
        temp = temp->next;
    }  
    return temp;
}

void deleteItem(List *ls, string itemID)
{
    Coffee *del = searchItem(ls, itemID);

    if (ls->head == NULL || del == NULL)
        return;
 
    if (ls->head == del)
        ls->head = del->next;
    
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    if (del->prev != NULL) {
        del->prev->next = del->next;
        if(del->next == NULL) {
            ls->tail = del->prev;
        }
    }

    /* Finally, free the memory occupied by del*/
    delete del;
    ls->n = ls->n - 1;
}

void updateItem(List *ls, string itemID) {
    cout << "Enter ID to Search: ";
    cin >> itemID;

    Coffee *temp = searchItem(ls, itemID);
    while(temp == NULL) {
        cout << "Item Not Found!! Enter ID Again: ";
        cin >> itemID;
        temp = searchItem(ls, itemID);
    }

    string newName, newPrice;
    cout << "\n----------------" << endl;
    cout << "Updating Input: " << endl;
    cout << "----------------" << endl;

    cout << "Enter Item Name: ";
    cin >> newName;
    temp->name = newName;
    cout << "Enter Price Name: ";
    cin >> newPrice;
    temp->price = newPrice;
}

void displayList(List *ls) {
    Coffee *temp = new Coffee();
    temp = ls->head;
    while(temp != NULL) {
        cout << temp->id << setw(15) << temp->name << setw(15) << temp->price << endl;
        temp = temp->next;
    }
    cout << endl;
}

void displayReverseList(List *ls) {
    Coffee *temp = new Coffee();
    temp = ls->tail;
    while(temp != NULL) {
        cout << temp->id << "\t" << temp->name << "\t" << temp->price << endl;
        temp = temp->prev;
    }
    cout << endl;
}

void writeFile(List *ls) {
    ofstream file;
    file.open("ItemList.txt");

    Coffee *temp = new Coffee();
    temp = ls->head;
    while(temp != NULL) {
        file << temp->id << "\t" << temp->name << "\t" << temp->price << endl;
        temp = temp->next;
    }

    file.close();
}

List *readFile() {
    ifstream file;
    file.open("ItemList.txt");
    string id, name, price;

    List *L2 = createEmptyList();

    while(file >> id >> name >> price) {
        insertBegin(L2, id, name, price);
    }

    file.close();
    
    return L2; 
}

void deleteAllItem(List *ls) {
    Coffee *temp = new Coffee();
    while(ls->head != NULL) {
        temp = ls->head;
        ls->head = ls->head->next;
        delete temp;
    }

    ls->tail = NULL;
    ls->n = 0;
}