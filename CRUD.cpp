#include <iostream>
#include <fstream>
using namespace std;

struct Coffee {
    string id, name;
    float price;
    Coffee *next;
    Coffee *prev;
};

struct List {
    int n;
    Coffee *head;
    Coffee *tail;
};

List *createList() {
    List *ls = new List();

    ls->n = 0;
    ls->head = NULL;
    ls->tail = NULL;

    return ls;
}

void insertBegin(List *ls, string itemID, string itemName, float itemPrice) {
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


int main() {


    return 0;
}