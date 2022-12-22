#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include <vector>
#include "password.h";
#include "Donor.h";

int main() {
    string my_password;
    vector<Donor>obj(100);
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
    int num = 0;
    obj[0].refrish(&num);
    obj[0].update(obj, num);
    cout << "\nthe number of Donors in the system : " << num << endl;
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
            obj[0].search(obj, num);
            break;
        case 'A':
        case 'a':
            obj[0].add_new(obj, &num);
            break;
        case 'E':
        case 'e':
            obj[0].edit_data(obj, &num);
            obj[0].overwrite_data(obj, num);
            break;
        case 'D':
        case 'd':
            obj[0].delete_element(obj, &num);
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
