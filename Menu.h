void coffeeList() {
    List *ls = readFile();
    cout << "ID" << setw(15) << "Name" << setw(15) << "Price" << endl;
    displayList(ls);
}
