#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include <vector>
#include "password.h"

string password::decrypt(string password) {
    for (int i = 0; i < password.size(); i++) {
        password[i] += password.size() + i;
    }
    return password;
}

string password::encrypt(string password) {
    for (int i = 0; i < password.size(); i++) {
        password[i] -= password.size() + i;
    }
    return password;
}

password::password() {
    fstream file;
    file.open("password.txt", ios::in);
    if (file.is_open()) {
        getline(file, y);
        y = decrypt(y);
        file.close();
    }
}

void password::set_password(string p) {
    x = p;
}

bool password::check_password() {
    if (x == y) return false;
    return true;
}

bool password::check_legitpassword(string password) {
    bool haslower = true, hasupper = true, hasdigit = true;

    if (password.length() < 8) {
        cout << "your password must have at least <8> digits.\n";
        return false;
    }

    for (int i = 0; i < password.length(); i++) {
        if (islower(password[i]))
            haslower = false;
        if (isupper(password[i]))
            hasupper = false;
        if (isdigit(password[i]))
            hasdigit = false;
    }

    if (haslower)
        cout << "your password must have at least <1> lowercase character.\n";
    else if (hasupper)
        cout << "your password must have at least <1> uppercase character.\n";
    else if (hasdigit)
        cout << "your password must have at least <1> digit character.\n";
    if (haslower || hasupper || hasdigit)
        return false;
    else
        return true;
}

void password::set_newpassword(void) {
    cout << "enter the old password: ";
    do {
        cin >> x;
        if (!check_password()) {
            cout << "please enter a new password or < 0 > to return to menu : ";
            while (true) {
                cin >> x;
                if (x != "0" && check_legitpassword(x)) {
                    cout << "password has changed successfully\n";
                    fstream file;
                    file.open("password.txt", ios::out);
                    if (file.is_open()) {
                        file << encrypt(x);
                        file.close();
                    }
                    y = x;
                    break;
                }
                else if (x == "0") break;
                else cout << "please enter a new password with match constraints or < 0 > to return to menu: ";
            }
        }
        else if (x != "0" && check_password()) cout << "please enter a correct password or < 0 > to return to menu: ";
    } while (check_password() && x != "0");
}
