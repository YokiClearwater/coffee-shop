#include <iostream>
#include <fstream>
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

void displayList(List *ls) {
    Coffee *temp = new Coffee();
    temp = ls->head;
    while(temp != NULL) {
        cout << temp->id << "\t" << temp->name << "\t" << temp->price << endl;
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

int main() {
    List *L1 = createEmptyList();

    insertBegin(L1, "1", "Latte", "123.5");
    insertBegin(L1, "2", "Americano", "123.5");
    insertBegin(L1, "3", "Ice-Cream", "123.5");

    displayList(L1);

    displayReverseList(L1);

    writeFile(L1);

    List *L2 = readFile(); // Text File Shouldn't have a space

    displayList(L2);

    return 0;
}