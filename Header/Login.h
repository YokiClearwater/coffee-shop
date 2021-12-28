

struct UserLogin {
    string userName, password;
    UserLogin *next;
    UserLogin *prev;
};

struct LoginList {
    int n;
    UserLogin *head;
    UserLogin *tail;
};

LoginList *createEmptyLoginList() {
    LoginList *ls = new LoginList();

    ls->n = 0;
    ls->head = NULL;
    ls->tail = NULL;

    return ls;
}

void insertLoginBegin(LoginList *ls, string newName, string newPass) {
    UserLogin *user = new UserLogin();
    user->userName = newName;  
    user->password = newPass;
    user->prev = NULL;
    user->next = ls->head;

    if(ls->n == 0) {
        ls->tail = user;
    }

    if(ls->n != 0) {
        ls->head->prev = user;
    }
    ls->head = user;
    ls->n += 1;
}

void insertLoginEnd(LoginList *ls, string newName, string newPass) {
    if(ls->n == 0) {
        insertLoginBegin(ls, newName, newPass);
    }
    else {
        UserLogin *user = new UserLogin();
        user->userName = newName;  
        user->password = newPass; 
        user->next = NULL;
        user->prev = ls->tail;
        ls->tail->next = user;
        ls->tail = user;
        ls->n = ls->n + 1;

    }
}

UserLogin *searchUserLogin(LoginList *ls, string name) {
    UserLogin *temp = ls->head;
    int count = 0;

    while(temp != NULL) {
        count++;
        if(temp->userName == name) {
            break;
        }
        temp = temp->next;
    }  
    return temp;
}

void writeLoginFile(LoginList *ls) {
    ofstream file;
    file.open("LoginData.txt");

    UserLogin *temp = new UserLogin();
    temp = ls->head;
    while(temp != NULL) {
        file << temp->userName << "\t" << temp->password << endl;
        temp = temp->next;
    }

    file.close();
}

LoginList *readLoginFile() {
    ifstream file;
    file.open("LoginData.txt");
    string userName, password;

    LoginList *L2 = createEmptyLoginList();

    while(file >> userName >> password) {
        insertLoginBegin(L2, userName, password);
    }

    file.close();
    
    return L2; 
}

string getPassword()
{ 
    string password;
    int ch;

    while ( ( ch = getch() ) != '\r' ) {
        if ( ch == '\b' ) {
            if ( password.size() > 0 ) {
                password.erase( password.size() - 1, 1 );
                cout<<"\b \b";
            }
        }
        else {
            password.push_back( ch );
            cout.put ( '*' );
        }
    }

    cout.put ( '\n' );

    return password;
}

void inputPass(string password) {
    #ifdef _WIN32
    password = getPassword();
    #endif
    
    #ifdef __unix__
    password = getpass("");
    #endif
}

void signUp() {
    LoginList *LL = readLoginFile();

    string userName, password, confirmPass;

    cout << "Enter Username: ";
    cin >> userName;

    UserLogin *U1 = searchUserLogin(LL, userName);
    while(U1 != NULL) {
        cout << "User Name is already taken!! Enter Another Name: ";
        cin >> userName;
        U1 = searchUserLogin(LL, userName);
    }

    cout << "Enter Password: ";
    inputPass(password);

    cout << "Confirm Password: ";
    inputPass(confirmPass);

    while(password != confirmPass) {
        cout << "Password Doesn't Match!! Enter Again!" << endl;
        cout << "Enter Password: ";
        inputPass(password);
        cout << "Confirm Password: ";
        inputPass(confirmPass);
    }

    if(password.size() == 0 || confirmPass.size() == 0) {
        cout << "Sign Up Unsucessful, You didn't enter a password!" << endl;
        return;
    }

    insertLoginBegin(LL, userName, password);
    writeLoginFile(LL);
}

UserLogin *logIn() {
    LoginList *LL = readLoginFile();
    string userName, password;

    cout << "Enter Username: ";
    cin >> userName;
    cout << "Enter Password: ";
    cin >> password;

    UserLogin *U1 = searchUserLogin(LL, userName);
    while(true) {
        if(U1 != NULL && password == U1->password) {
            break;
        }
        else {
            cout << "Incorrect Username or Password!! Enter Again!!" << endl;
            cout << "Enter Username: ";
            cin >> userName;
            cout << "Enter Password: ";
            cin >> password;
            U1 = searchUserLogin(LL, userName);
        }
    }

    return U1;
}

