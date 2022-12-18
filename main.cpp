#include<iostream>
#include<fstream>
#include<string>
#include <vector>
using namespace std;

class password {
private:
	string x, y;
	string decrypt(string password) {
		for (int i = 0; i < password.size(); i++) {
			password[i] += password.size() + i;
		}
		return password;
	}
	string encrypt(string password) {
		for (int i = 0; i < password.size(); i++) {
			password[i] -= password.size() + i;
		}
		return password;
	}
public:
	password(void) {
		fstream file;
		file.open("password.txt", ios::in);
		if (file.is_open()) {
			getline(file, y);
			y = decrypt(y);
			file.close();
		}
	}

	void set_password(string p) {
		x = p;
	}

	bool check_password() {
		if (x == y) return false;
		return true;
	}

	bool check_legitpassword(string password) {
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

	void set_newpassword(void) {
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
};

class Patient {
private:
	string name, BloodType, mobile, age, id;
public:
	// constructors
	Patient() {}
	Patient(string name, string bloodType, string age, string mobile, string id);
	// setters
	void setName(string name);
	void setBloodType(string BloodType);
	void setAge(string age);
	void setMobile(string mobile);
	void setID(string id);
	// getters
	string getName() { return name; }
	string getBloodType() { return BloodType; }
	string getMobile() { return mobile; }
	string getAge() { return age; }
	string getID() { return id; }
	// other functions
	void readData();
	void printData();
};


Patient::Patient(string name, string bloodType, string age, string mobile, string id) {
	this->name = name;
	this->BloodType = bloodType;
	this->age = age;
	this->mobile = mobile;
	this->id = id;
}

void Patient::setName(string name) {
	this->name = name;
}

void Patient::setBloodType(string BloodType) {
	this->BloodType = BloodType;
}

void Patient::setMobile(string mobile) {
	this->mobile = mobile;
}

void Patient::setAge(string age) {
	this->age = age;
}

void Patient::setID(string id) {
	this->id = id;
}

void Patient::readData() {
	string name, bloodType, mobile, age, id;
	cout << "Please enter the patient's data: \n";
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

void Patient::printData() {
	cout << "Name: " << getName() << endl;
	cout << "Blood Type: " << getBloodType() << endl;
	cout << "Mobile: " << getMobile() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "ID: " << getID() << endl;
}

void Search_no(vector<Patient>obj, int num, int i) {
	if (i > 0 && i <= num) {
		i--;
		cout << "*********************\n";
		cout << "Name: " << obj[i].getName() << endl;
		cout << "BloodType: " << obj[i].getBloodType() << endl;
		cout << "Mobilee: " << obj[i].getMobile() << endl;
		cout << "ID: " << obj[i].getID() << endl;
		cout << "Age: " << obj[i].getAge() << endl;
		cout << "*********************\n";
	}
	else cout << "it is not found\n";
}
void refrish(int* p) {
	fstream file;
	file.open("data.txt", ios::in);
	if (file.is_open()) {
		string t;
		while (!file.eof()) {
			getline(file, t);
            if(t.size())
               (*p)++;
            file >> ws;
		}
		file.close();
	}
}
void update(vector<Patient>& obj, int num) {
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
int delete_element(vector<Patient> &obj1, int *p) {
	    string x;
	    char y;
	    cout<<"Enter id of patient: ";
	    cin>>x;
	    cout<<"\nare you sure about this deletion process? Enter <Y> or <N>  ";
	    cin>>y;
	    if (y == 'y' || y == 'Y')
        {
            for (int i=0;i<*p;i++)
            {
            if(x == obj1[i].getID())
            {
                obj1.erase(obj1.begin()+i);
                (*p)--;
                fstream file;
                file.open("data.txt", ios::out);
                if (file.is_open()) {
                for (int i = 0;i<*p;i++)
                {
                file << obj1[i].getName() << ",";
                file << obj1[i].getBloodType() << ";";
                file << obj1[i].getMobile() << "/";
                file << obj1[i].getID() << ":";
                file << obj1[i].getAge() << ".\n";
                }
                }
                file.close();
                cout<<"\npatient's data has been deleted successfully\n";
                cout <<"\nthe current number of patients: "<<*p<<"\n\n";
                return 0;
            }
            }
            cout<<"\nid not found\n\n";
            return 0;
        }
	    if (y == 'n' || y == 'N')
            return 0;

}
void app_data(vector<Patient>& obj, int num) {
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
int add_new(vector<Patient>& obj1, int* p) {
	string x1;
	cout << "\nPatient #" << *p + 1 <<"\n\n";
	cout << "name: ";
	cin.ignore();
	getline(cin,x1);
	obj1[*p].setName(x1);

	while(true)
    {
    cout<<"Blood type: ";
    cin >> x1;
    if(x1 == "A+" || x1 == "A-")
    {
        obj1[*p].setBloodType(x1);
        break;
    }
    else if(x1 == "B+" || x1 == "B-")
    {
        obj1[*p].setBloodType(x1);
        break;
    }
    else if(x1 == "O+" || x1 == "O-")
    {
        obj1[*p].setBloodType(x1);
        break;
    }
    else if(x1 == "AB+" || x1 == "AB-")
    {
        obj1[*p].setBloodType(x1);
        break;
    }
    else cout<<"\nInvalid Blood type\n\n";
    }

	while(true)
    {
    cout << "mobile: ";
    cin >> x1;
    if(x1.find_first_not_of("0123456789") == string::npos && x1.length() == 11)
    {
        obj1[*p].setMobile(x1);
        break;
    }
    else cout<<"\nInvalid phone number\n\n";
    }

	while(true)
    {
    cout << "id: ";
    cin >> x1;
    if(x1.find_first_not_of("0123456789") == string::npos && x1.length() == 14)
    {
        obj1[*p].setID(x1);
        break;
    }
    else cout<<"\nInvalid ID\n\n";
    }

	while(true)
    {
    cout<<"Enter age: ";
    cin >> x1;
    if(x1.find_first_not_of("0123456789") == string::npos && stoi(x1) >= 18 && stoi(x1) <= 65 )
    {
        obj1[*p].setAge(x1);
        break;
    }
    else
    cout<<"\nage is Invalid or not qualified for donation, data will be terminated\n\n";
    return 0;
    }

	(*p)++;
	app_data(obj1, *(p));
	cout <<"\nthe current number of patients: "<<*p<<"\n\n";
	return 0;
}
int main() {
	string my_password;
	vector<Patient>obj(100);
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
	refrish(&num);
	update(obj, num);
	cout << "\nthe number of patients in the system : " << num << endl;
	char tester;
	while(true){
		cout << "\nto change your password ,| enter <C> |\n";
		cout << "to Search               ,| enter <S> |\n";
		cout << "to Add data             ,| enter <A> |\n";
		cout << "to delete data          ,| enter <D> |\n";
		cout << "to Edit data            ,| enter <E> |\n";
		cout << "to Quit                 ,| enter <Q> |\n";
		cin >> tester;
		if (tester == 'C' || tester == 'c')owner.set_newpassword();
		if (tester == 'S' || tester == 's') {
			int i = 0;
			cout << "the no. of patiant : ";
			cin >> i;
			Search_no(obj, num, i);
		}
		if (tester == 'A' || tester == 'a')
			add_new(obj, &num);
		if (tester == 'E' || tester == 'e');
		if (tester == 'd' || tester == 'D')
            		delete_element(obj, &num);
		if (tester == 'Q' || tester == 'q')break;
	}
}
