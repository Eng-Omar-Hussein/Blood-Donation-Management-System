#include<iostream>
using namespace std;
#include<fstream>
#include <string>
#include <vector>
#include "Donor.h"
struct counter {
    int ABpos = 0, ABneg = 0, Apos = 0, Aneg = 0;
    int Bpos = 0, Bneg = 0, Opos = 0, Oneg = 0;
};

counter BloodTypeCount;


int Donor::delete_element(vector<Donor>& obj1) {
    string x;
    char y;
    cout << "Enter id of Donor: ";
    cin >> x;
    cout << "\nare you sure about this deletion process? Enter <Y> or <N>  ";
    cin >> y;
    if (y == 'y' || y == 'Y')
    {
        for (int i = 0; i < obj1.size(); i++)
        {
            if (x == obj1[i].getID())
            {
                if (obj1[i].getBloodType() == "A+")
                    BloodTypeCount.Apos--;
                else if (obj1[i].getBloodType() == "A-")
                    BloodTypeCount.Aneg--;
                else if (obj1[i].getBloodType() == "B+")
                    BloodTypeCount.Bpos--;
                else if (obj1[i].getBloodType() == "B-")
                    BloodTypeCount.Bneg--;
                else if (obj1[i].getBloodType() == "AB+")
                    BloodTypeCount.ABpos--;
                else if (obj1[i].getBloodType() == "AB-")
                    BloodTypeCount.ABneg--;
                else if (obj1[i].getBloodType() == "O+")
                    BloodTypeCount.Opos--;
                else
                    BloodTypeCount.Oneg--;

                obj1.erase(obj1.begin() + i);
                overwrite_data(obj1);
                cout << "\nDonor's data has been deleted successfully\n";
                cout << "\nthe current number of Donors: " << obj1.size() << "\n\n";
                return 0;
            }
        }
        cout << "\nid not found\n\n";
        return 0;
    }
    if (y == 'n' || y == 'N')
        return 0;
}


Donor::Donor() {
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

void Donor::printData_header() {
    system("CLS");
    cout << "=======================================================================================================================================================================" << endl;
    cout << "=======================================================================| Data Found |==================================================================================" << endl;
    cout << "=======================================================================================================================================================================" << endl;
    cout << "        No.:     |          BloodType             |           ID            |             Mobile        |              Age            |              NAME" << endl;
    cout << "_______________________________________________________________________________________________________________________________________________________________________" << endl;
}

void Donor::printData(vector<Donor>obj, int i) {

        cout << "\t" << i + 1 << "\t\t\t" << obj[i].getBloodType() << "\t\t\t" << obj[i].getID() << "\t\t\t" << obj[i].getMobile() << "\t\t\t" << obj[i].getAge() << "\t\t\t" << obj[i].getName() << endl;
}

void Donor::printData_foater() {
    cout << "=======================================================================================================================================================================" << endl;
}

void Donor::add_new(vector<Donor>& obj) {
    Donor temp;
    string x1;
    cout << "\nDonor #" << obj.size() + 1 << "\n\n";
    cout << "name: ";
    cin.ignore();
    getline(cin, x1);
    temp.setName(x1);

    while (true) {
        cout << "Blood type: ";
        cin >> x1;
        
        if (check_BloodType(x1))
        {
            if (x1 == "A+")
                BloodTypeCount.Apos++;
            else if (x1 == "A-")
                BloodTypeCount.Aneg++;
            else if (x1 == "B+")
                BloodTypeCount.Bpos++;
            else if (x1 == "B-")
                BloodTypeCount.Bneg++;
            else if (x1 == "AB+")
                BloodTypeCount.ABpos++;
            else if (x1 == "AB-")
                BloodTypeCount.ABneg++;
            else if (x1 == "O+")
                BloodTypeCount.Opos++;
            else
                BloodTypeCount.Oneg++;

            temp.setBloodType(x1);
            break;
        }
        else cout << "\nInvalid Blood type\n\n";
    }

    while (true) {
        cout << "mobile: ";
        cin >> x1;
        if (check_mobile(x1))
        {
            temp.setMobile(x1);
            break;
        }
        else cout << "\nInvalid phone number\n\n";
    }

    while (true) {
        cout << "id: ";
        cin >> x1;
        if (check_ID(x1, obj))
        {
            temp.setID(x1);
            break;
        }
        if (!check_Duplicate_ID(x1, obj))
            cout << "\nDuplicated ID\n\n";
        else
            cout << "\nInvalid ID\n\n";
    }

    while (true)
    {
        cout << "Enter age: ";
        cin >> x1;
        if (check_age(x1))
        {
            temp.setAge(x1);
            break;
        }
        else cout << "\nage is Invalid\n\n";
    }
    obj.push_back(temp);
    app_data(obj);
    cout << "\nDonor #" << obj.size() << " has been added successfully\n";
    cout << "\nthe current number of Donors: " << obj.size() << "\n\n";
}

void Donor::edit_data(vector<Donor>& obj1) {
    string x;
    cout << "Enter the Donor's id: ";
    cin >> x;
    for (int i = 0; i < obj1.size(); i++)
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

                    if (obj1[i].getBloodType() == "A+")
                        BloodTypeCount.Apos--;
                    else if (obj1[i].getBloodType() == "A-")
                        BloodTypeCount.Aneg--;
                    else if (obj1[i].getBloodType() == "B+")
                        BloodTypeCount.Bpos--;
                    else if (obj1[i].getBloodType() == "B-")
                        BloodTypeCount.Bneg--;
                    else if (obj1[i].getBloodType() == "AB+")
                        BloodTypeCount.ABpos--;
                    else if (obj1[i].getBloodType() == "AB-")
                        BloodTypeCount.ABneg--;
                    else if (obj1[i].getBloodType() == "O+")
                        BloodTypeCount.Opos--;
                    else
                        BloodTypeCount.Oneg--;

                    while (true) {
                        cout << "Enter the new blood type: ";
                        cin >> y;
                        if (obj1[i].check_BloodType(y))
                        {
                            if (y == "A+")
                                BloodTypeCount.Apos++;
                            else if (y == "A-")
                                BloodTypeCount.Aneg++;
                            else if (y == "B+")
                                BloodTypeCount.Bpos++;
                            else if (y == "B-")
                                BloodTypeCount.Bneg++;
                            else if (y == "AB+")
                                BloodTypeCount.ABpos++;
                            else if (y == "AB-")
                                BloodTypeCount.ABneg++;
                            else if (y == "O+")
                                BloodTypeCount.Opos++;
                            else
                                BloodTypeCount.Oneg++;

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
                        if (obj1[i].check_ID(y, obj1))
                        {
                            obj1[i].setID(y);
                            break;
                        }
                        if (!check_Duplicate_ID(y, obj1))
                            cout << "\nDuplicated ID\n\n";
                        else
                            cout << "\nInvalid ID\n\n";
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

void Donor::update(vector<Donor>& obj) {
    Donor temp1;
    bool found = false;
    string temp;
    fstream file;
    file.open("data.txt", ios::in);
    if (file.is_open()) {
        string t;
        while (!file.eof()) {
            getline(file, t);
            if (t.size())
                found = true;
            file >> ws;
        }
    }
    file.close();
    if (found) {
        fstream file;
        file.open("data.txt", ios::in);
        if (file.is_open()) {
            while (!file.eof()) {
                file >> ws;
                getline(file, temp);
                temp1.setName(temp.substr(0, temp.find(",")));
                temp1.setBloodType(temp.substr(temp.find(",") + 1, temp.find(";") - temp.find(",") - 1));
                temp1.setMobile(temp.substr(temp.find(";") + 1, temp.find("/") - temp.find(";") - 1));
                temp1.setID(temp.substr(temp.find("/") + 1, temp.find(":") - temp.find("/") - 1));
                temp1.setAge(temp.substr(temp.find(":") + 1, temp.find(".") - temp.find(":") - 1));
                obj.push_back(temp1);
                file >> ws;
            }
            file.close();
        }
    }
}

void Donor::overwrite_data(vector<Donor>& obj) {
    fstream file;
    file.open("data.txt", ios::out);
    if (file.is_open()) {
        for (int i = 0; i < obj.size(); i++)
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

void Donor::app_data(vector<Donor>& obj) {
    fstream file;
    file.open("data.txt", ios::app);
    if (file.is_open()) {
        file << obj[(obj.size() - 1)].getName() << ",";
        file << obj[(obj.size() - 1)].getBloodType() << ";";
        file << obj[(obj.size() - 1)].getMobile() << "/";
        file << obj[(obj.size() - 1)].getID() << ":";
        file << obj[(obj.size() - 1)].getAge() << ".\n";
        file.close();
    }
}

void Donor::search(vector<Donor>obj) {
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
        switch (choice) {
        case '1':
            cout << "Enter the Donor's id: ";
            cin >> x;
            printData_header();
            for (int i = 0; i < obj.size(); i++)
            {
                if (x == obj[i].getID()) {
                    printData(obj, i);
                    t = false;
                }
            }
            printData_foater();
            if (t)cout << "\nID was not found\n\n";
            break;
        case '2':
            cout << "the no. of Donor : ";
            cin >> i;
            Search_no(obj, i);
            break;
        case '3':
            while (true)
            {
                cout << "Enter recipient blood type: ";
                cin >> x;
                if (check_BloodType(x))
                {
                    search_recip(obj, x);
                    break;
                }
                else
                    cout << "\nInvalid Blood Type\n\n";
            }
            break;
        case '4':
            Search_BloodType(obj);
            break;
        case '5':
            return;
        default:
            break;
        }
    }
}

void Donor::search_recip(vector<Donor>obj, string x) {
    bool found = false;
    if (x == "AB+")
    {
        printData_header();
        for (int i = 0; i < obj.size(); i++)
            printData(obj, i);
        printData_foater();
    }
    else if (x == "AB-")
    {
        printData_header();
        for (int i = 0; i < obj.size(); i++)
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
        for (int i = 0; i < obj.size(); i++)
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
        for (int i = 0; i < obj.size(); i++)
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
        for (int i = 0; i < obj.size(); i++)
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
        for (int i = 0; i < obj.size(); i++)
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
        for (int i = 0; i < obj.size(); i++)
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
        for (int i = 0; i < obj.size(); i++)
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

void Donor::Search_BloodType(vector<Donor>obj) {
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
    for (int i = 0; i < obj.size(); i++) {
        if (obj[i].getBloodType() == Donorbloodtype) {
            counter = true;
            printData(obj, i);
        }
    }
    printData_foater();
    if (counter) {
        cout << "The number of blood bags of type " << Donorbloodtype << " in the system are: ";
        if (Donorbloodtype == "A+")
            cout << BloodTypeCount.Apos << endl;
        else if (Donorbloodtype == "A-")
            cout << BloodTypeCount.Aneg << endl;
        else if (Donorbloodtype == "B+")
            cout << BloodTypeCount.Bpos << endl;
        else if (Donorbloodtype == "B-")
            cout << BloodTypeCount.Bneg << endl;
        else if (Donorbloodtype == "AB+")
            cout << BloodTypeCount.ABpos << endl;
        else if (Donorbloodtype == "AB-")
            cout << BloodTypeCount.ABneg << endl;
        else if (Donorbloodtype == "O+")
            cout << BloodTypeCount.Opos << endl;
        else
            cout << BloodTypeCount.Oneg << endl;
        printData_foater();
    }
    if (!counter)
        cout << "\nNo Records Found !\n\n";
}

void Donor::Search_no(vector<Donor>obj, int i) {
    printData_header();
    if (i > 0 && i <= obj.size()) {
        i--;
        printData(obj, i);
    }
    printData_foater();
    if (i <= 0 || i > obj.size())
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

bool Donor::check_Duplicate_ID(string x, vector<Donor>obj) {
    for (int i = 0; i < obj.size(); i++)
        if (obj[i].getID() == x) return false;
    return true;
}
bool Donor::check_ID(string x, vector<Donor>obj) {
    if (x.find_first_not_of("0123456789") == string::npos && x.length() == 14 && check_Duplicate_ID(x, obj))
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
