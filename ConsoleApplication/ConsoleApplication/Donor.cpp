#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include <vector>
#include "Donor.h"

int Donor::delete_element(vector<Donor>& obj1, int* p) {
    string x;
    char y;
    cout << "Enter id of Donor: ";
    cin >> x;
    cout << "\nare you sure about this deletion process? Enter <Y> or <N>  ";
    cin >> y;
    if (y == 'y' || y == 'Y')
    {
        for (int i = 0; i < *p; i++)
        {
            if (x == obj1[i].getID())
            {
                obj1.erase(obj1.begin() + i);
                (*p)--;
                overwrite_data(obj1, *p);
                cout << "\nDonor's data has been deleted successfully\n";
                cout << "\nthe current number of Donors: " << *p << "\n\n";
                return 0;
            }
        }
        cout << "\nid not found\n\n";
        return 0;
    }
    if (y == 'n' || y == 'N')
        return 0;
}

Donor::Donor(string name, string bloodType, string age, string mobile, string id) {
    this->name = name;
    this->BloodType = bloodType;
    this->age = age;
    this->mobile = mobile;
    this->id = id;
}

Donor::Donor(){
}

string Donor::getName() {
    return name;
}

string Donor::getBloodType() {
    return BloodType;
}

string Donor::getMobile() {
    return mobile;
}

string Donor::getAge() {
    return age;
}

string Donor::getID() {
    return id;
}

void Donor::setName(string name) {
    this->name = name;
}

void Donor::setBloodType(string BloodType) {
    this->BloodType = BloodType;
}

void Donor::setAge(string age) {
    this->age = age;
}

void Donor::setMobile(string mobile) {
    this->mobile = mobile;
}

void Donor::setID(string id) {
    this->id = id;
}

void Donor::readData() {
    string name, bloodType, mobile, age, id;
    cout << "Please enter the Donor's data: \n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, name); setName(name);
    cout << "Blood Type: ";
    cin >> BloodType; setBloodType(bloodType);
    cout << "Mobile: ";
    cin >> mobile; setMobile(mobile);
    cout << "Age: ";
    cin >> age; setAge(age);
    cout << "ID: ";
    cin >> id; setID(id);
    cout << endl;
}

void Donor::printData_header(){
    system("CLS");
    cout << "=======================================================================================================================================================================" << endl;
    cout << "=======================================================================| Data Found |==================================================================================" << endl;
    cout << "=======================================================================================================================================================================" << endl;
    cout << "        NO :    |          BloodType:             |           ID            |             Mobile        |              Age           |               NAME" << endl;
    cout << "_______________________________________________________________________________________________________________________________________________________________________" << endl;
}

void Donor::printData(vector<Donor>obj, int i) {

    cout << "\t" << i+1 << "\t\t\t" << obj[i].getBloodType() << "\t\t\t" << obj[i].getID() << "\t\t\t" << obj[i].getMobile() << "\t\t\t" << obj[i].getAge() << "\t\t\t" << obj[i].getName() << endl;
}

void Donor::printData_foater() {
    cout << "=======================================================================================================================================================================" << endl;
}

void Donor::add_new(vector<Donor>& obj1, int* p) {
    string x1;
    cout << "\nDonor #" << *p + 1 << "\n\n";
    cout << "name: ";
    cin.ignore();
    getline(cin, x1);
    obj1[*p].setName(x1);

    while (true) {
        cout << "Blood type: ";
        cin >> x1;
        if (check_BloodType(x1))
        {
            obj1[*p].setBloodType(x1);
            break;
        }
        else cout << "\nInvalid Blood type\n\n";
    }

    while (true) {
        cout << "mobile: ";
        cin >> x1;
        if (check_mobile(x1))
        {
            obj1[*p].setMobile(x1);
            break;
        }
        else cout << "\nInvalid phone number\n\n";
    }

    while (true) {
        cout << "id: ";
        cin >> x1;
        if (check_ID(x1))
        {
            obj1[*p].setID(x1);
            break;
        }
        else cout << "\nInvalid ID\n\n";
    }

    while (true)
    {
        cout << "Enter age: ";
        cin >> x1;
        if (check_age(x1))
        {
            obj1[*p].setAge(x1);
            break;
        }
        else
            cout << "\nage is Invalid\n\n";
    }
    (*p)++;
    app_data(obj1, *(p));
    cout << "\nDonor #" << *p << " has been added successfully\n";
    cout << "\nthe current number of Donors: " << *p << "\n\n";
}

void Donor::edit_data(vector<Donor>& obj1, int* p) {
    string x;
    cout << "Enter the Donor's id: ";
    cin >> x;
    for (int i = 0; i < *p; i++)
    {
        if (x == obj1[i].getID())
        {
            string y;
            char choice;
            cout << "Editing data of Donor #" << i + 1 << endl;
            while (true) {
                cout << "\n1) edit name\n";
                cout << "2) edit blood type\n";
                cout << "3) edit mobile\n";
                cout << "4) edit ID\n";
                cout << "5) edit age\n";
                cout << "6) return to main menu\n";
                cout << "Please enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case '1':
                    cout << "Enter the new name: ";
                    cin.ignore();
                    getline(cin, y);
                    obj1[i].setName(y);
                    break;
                case '2':
                    while (true) {
                        cout << "Enter the new blood type: ";
                        cin >> y;
                        if (obj1[i].check_BloodType(y))
                        {
                            obj1[i].setBloodType(y);
                            break;
                        }
                        else cout << "\nInvalid Blood type\n\n";
                    }
                    break;
                case '3':
                    while (true) {
                        cout << "Enter the new mobile: ";
                        cin >> y;
                        if (obj1[i].check_mobile(y))
                        {
                            obj1[i].setMobile(y);
                            break;
                        }
                        else cout << "\nInvalid phone number\n\n";
                    }
                    break;
                case '4':
                    while (true) {
                        cout << "Enter the new id: ";
                        cin >> y;
                        if (obj1[i].check_ID(y))
                        {
                            obj1[i].setID(y);
                            break;
                        }
                        else cout << "\nInvalid ID\n\n";
                    }
                    break;
                case '5':
                    while (true) {
                        cout << "Enter the new age: ";
                        cin >> y;
                        if (obj1[i].check_age(y))
                        {
                            obj1[i].setAge(y);
                            break;
                        }
                        else cout << "\nInvalid Age\n\n";
                    }
                    break;
                case '6':
                    return;
                default:
                    break;
                }
            }
        }
    }
    cout << "\nid not found\n\n";
}

void Donor::refrish(int* p) {
    fstream file;
    file.open("data.txt", ios::in);
    if (file.is_open()) {
        string t;
        while (!file.eof()) {
            getline(file, t);
            if (t.size())
                (*p)++;
            file >> ws;
        }
        file.close();
    }
}

void Donor::update(vector<Donor>& obj, int num) {
    fstream file;
    file.open("data.txt", ios::in);
    if (file.is_open()) {
        string temp;
        for (int i = 0; i < num; i++) {
            file >> ws;
            getline(file, temp);
            obj[i].setName(temp.substr(0, temp.find(",")));
            obj[i].setBloodType(temp.substr(temp.find(",") + 1, temp.find(";") - temp.find(",") - 1));
            obj[i].setMobile(temp.substr(temp.find(";") + 1, temp.find("/") - temp.find(";") - 1));
            obj[i].setID(temp.substr(temp.find("/") + 1, temp.find(":") - temp.find("/") - 1));
            obj[i].setAge(temp.substr(temp.find(":") + 1, temp.find(".") - temp.find(":") - 1));
            file >> ws;
        }
        file.close();
    }
}

void Donor::overwrite_data(vector<Donor>& obj, int num) {
    fstream file;
    file.open("data.txt", ios::out);
    if (file.is_open()) {
        for (int i = 0; i < num; i++)
        {
            file << obj[i].getName() << ",";
            file << obj[i].getBloodType() << ";";
            file << obj[i].getMobile() << "/";
            file << obj[i].getID() << ":";
            file << obj[i].getAge() << ".\n";
        }
    }
    file.close();
}

void Donor::app_data(vector<Donor>& obj, int num) {
    fstream file;
    num--;
    file.open("data.txt", ios::app);
    if (file.is_open()) {
        file << obj[num].getName() << ",";
        file << obj[num].getBloodType() << ";";
        file << obj[num].getMobile() << "/";
        file << obj[num].getID() << ":";
        file << obj[num].getAge() << ".\n";
        file.close();
    }
}

void Donor::search(vector<Donor>obj, int num) {
    string x;
    int i;
    char choice;
    while (true) {
        bool t = true;
        cout << "\n1) search by id\n";
        cout << "2) search by number\n";
        cout << "3) search for donors\n";
        cout << "4) search by Blood Type\n";
        cout << "5) return to main menu\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice){
        case '1':
            cout << "Enter the Donor's id: ";
            cin >> x;
            printData_header();
            for (int i = 0; i < num; i++)
            {
                if (x == obj[i].getID()) {
                    printData(obj, i);
                    t = false;
                }
            }
            printData_foater();
            if(t)cout << "\nID was not found\n\n";
            break;
        case '2':
            cout << "the no. of Donor : ";
            cin >> i;
            Search_no(obj, num, i);
            break;
        case '3':
            while (true)
            {
                cout << "Enter recipient blood type: ";
                cin >> x;
                if (check_BloodType(x))
                {
                    search_recip(obj, num, x);
                    break;
                }
                else
                    cout << "\nInvalid Blood Type\n\n";
            }
            break;
        case '4':
            Search_BloodType(obj, num);
            break;
        case '5':
            return;
        default:
            break;
        }
    }
}

void Donor::search_recip(vector<Donor>obj, int num, string x) {
    bool found = false;
    if (x == "AB+")
    {
        printData_header();
        for (int i = 0; i < num; i++)
            printData(obj, i);
        printData_foater();
    }
    else if (x == "AB-")
    {
        printData_header();
        for (int i = 0; i < num; i++)
        {
            if (obj[i].getBloodType() == "O-" || obj[i].getBloodType() == "B-" || obj[i].getBloodType() == "A-" || obj[i].getBloodType() == "AB-")
            {
                found = true;
                printData(obj, i);
            }
        }
        printData_foater();
        if (!found)
            cout << "No donors have been found\n";
    }

    else if (x == "A+")
    {
        printData_header();
        for (int i = 0; i < num; i++)
        {
            if (obj[i].getBloodType() == "O-" || obj[i].getBloodType() == "O+" || obj[i].getBloodType() == "A-" || obj[i].getBloodType() == "A+")
            {
                found = true;
                printData(obj, i);
            }
        }
        printData_foater();
        if (!found)
            cout << "No donors have been found\n";
    }

    else if (x == "A-")
    {
        printData_header();
        for (int i = 0; i < num; i++)
        {
            if (obj[i].getBloodType() == "O-" || obj[i].getBloodType() == "A-")
            {
                found = true;
                printData(obj, i);
            }
        }
        printData_foater();
        if (!found)
            cout << "No donors have been found\n";
    }

    else if (x == "B+")
    {
        printData_header();
        for (int i = 0; i < num; i++)
        {
            if (obj[i].getBloodType() == "O-" || obj[i].getBloodType() == "O+" || obj[i].getBloodType() == "B-" || obj[i].getBloodType() == "B+")
            {
                found = true;
                printData(obj, i);
            }
        }
        printData_foater();
        if (!found)
            cout << "No donors have been found\n";
    }

    else if (x == "B-")
    {
        printData_header();
        for (int i = 0; i < num; i++)
        {
            if (obj[i].getBloodType() == "O-" || obj[i].getBloodType() == "B-")
            {
                found = true;
                printData(obj, i);
            }
        }
        printData_foater();
        if (!found)
            cout << "No donors have been found\n";
    }

    else if (x == "O+")
    {
        printData_header();
        for (int i = 0; i < num; i++)
        {
            if (obj[i].getBloodType() == "O-" || obj[i].getBloodType() == "O+")
            {
                found = true;
                printData(obj, i);
            }
        }
        printData_foater();
        if (!found)
            cout << "No donors have been found\n";
    }

    else if (x == "O-")
    {
        printData_header();
        for (int i = 0; i < num; i++)
        {
            if (obj[i].getBloodType() == "O-")
            {
                found = true;
                printData(obj, i);
            }
        }
        printData_foater();
        if (!found)
            cout << "No donors have been found\n";

    }
}

void Donor::Search_BloodType(vector<Donor>obj, int num) {
    string Donorbloodtype;
    while (true) {
        cout << "Enter blood type: ";
        cin >> Donorbloodtype;
        if (check_BloodType(Donorbloodtype))
            break;
        else
            cout << "\nInvalid Blood Type\n\n";
    }
    printData_header();
    bool counter = false;
    for (int i = 0; i < num; i++) {
        if (obj[i].getBloodType() == Donorbloodtype) {
            counter = true;
            printData(obj, i);
        }
    }
    printData_foater();
    if (!counter)
        cout << "\nNo Records Found !\n\n";
}

void Donor::Search_no(vector<Donor>obj, int num, int i) {
    printData_header();
    if (i > 0 && i <= num) {
        i--;
        printData(obj, i);
    }
    printData_foater();
    if (i <= 0 || i > num)
        cout << "\nDonor was not found\n\n";
}

bool Donor::check_BloodType(string x) {
    if (x == "A+" || x == "A-")
        return true;
    else if (x == "B+" || x == "B-")
        return true;
    else if (x == "O+" || x == "O-")
        return true;
    else if (x == "AB+" || x == "AB-")
        return true;
    else
        return false;
}

bool Donor::check_ID(string x) {
    if (x.find_first_not_of("0123456789") == string::npos && x.length() == 14)
        return true;
    else
        return false;
}

bool Donor::check_mobile(string x) {
    if (x.find_first_not_of("0123456789") == string::npos && x.length() == 11)
        return true;
    else
        return false;
}

bool Donor::check_age(string x) {
    if (x.find_first_not_of("0123456789") == string::npos)
        return true;
    else
        return false;
}
