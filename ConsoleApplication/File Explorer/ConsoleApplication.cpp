#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include <vector>
#include "password.h";
#include "Donor.h";

int main() {
    string my_password;
    vector<Donor>obj;
    Donor temp;
    password owner;
    do {
        cout << "please enter a correct password or < 0 > to quit: ";
        cin >> my_password;
        owner.set_password(my_password);
        if (my_password == "0") {
            cout << "see you soon\n";
            return 0;
        }
    } while (owner.check_password());
    temp.update(obj);
    cout << "\nthe number of Donors in the system : " << obj.size() << endl;
    char tester;
    while (true) {
        cout << "\nto change your password ,| enter <C> |\n";
        cout << "to Search               ,| enter <S> |\n";
        cout << "to Add data             ,| enter <A> |\n";
        cout << "to delete data          ,| enter <D> |\n";
        cout << "to Edit data            ,| enter <E> |\n";
        cout << "to clear screen         ,| enter <X> |\n";
        cout << "to Quit                 ,| enter <Q> |\n";
        cout << "Enter your option: ";
        cin >> tester;
        switch (tester){
        case 'C':
        case 'c':
            owner.set_newpassword();
            break;
        case 'S':
        case 's':
            temp.search(obj);
            break;
        case 'A':
        case 'a':
            temp.add_new(obj);
            break;
        case 'E':
        case 'e':
            temp.edit_data(obj);
            temp.overwrite_data(obj);
            break;
        case 'D':
        case 'd':
            temp.delete_element(obj);
            break;
        case 'Q':
        case 'q':
            cout << "\nSee you soon.\n";
            return 0;
            break;
        default:
            system("cls");
            break;
        }
    }
}
