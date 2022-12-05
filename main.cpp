#include<iostream>
#include<fstream>
#include<string>
#include <vector>
using namespace std;

class password {
private:
	string x,y;
	string encrypt(string password) {
		for (int i = 0; i < password.size(); i++) {
			password[i] += password.size() + i;
		}
		return password;
	}
	string decrypt(string password) {
		for (int i = 0; i < password.size(); i++) {
			password[i] -= password.size() + i;
		}
		return password;
	}
public:
    password(void){
        fstream file;
        file.open("password.txt", ios::in);
        if (file.is_open()){
            getline(file, y);
			y = encrypt(y);
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
		string z, new_passwor;
		do {
			cin >> z;
			if (z == y) {
				cout << "please enter a new password or < 0 > to return to menu : ";
				while (true) {
					cin >> new_passwor;
					if (new_passwor != "0" && check_legitpassword(new_passwor)) {
                        cout << "password has changed successfully\n";
                        fstream file;
                        file.open("password.txt", ios::out);
						new_passwor = decrypt(new_passwor);
                        if (file.is_open()) {
                            file<<new_passwor;
                            file.close();
                        }
						y = encrypt(new_passwor);
                        break;
					}
					else if(new_passwor == "0") break;
					else cout << "please enter a new password with match constraints or < 0 > to return to menu: ";
				}
			}
			else if (z != "0" && z != y) cout << "please enter a correct password or < 0 > to return to menu: ";
		} while (z != x && z != "0" && new_passwor != "0");
	}
};

class Patient {
    private:
        string name, BloodType, mobile;
        int age, id;
    public:
        // constructors
		Patient() {}
        Patient(string name, string bloodType, int age, string mobile, int id);
        // setters
        void setName(string name);
        void setBloodType(string setBloodType);
        void setAge(int age);
        void setMobile(string mobile);
		void setID(int id);
        // getters
        string getName() { return name; }
        string getBloodType() { return BloodType; }
        string getMobile() { return mobile; }
        int getAge() { return age; } 
		int getID() { return id; }
        // other functions
        void readData();
		void printData();
};


Patient::Patient(string name, string bloodType, int age, string mobile, int id) {
    this->name = name;
    this->BloodType = bloodType;
    this->age = age;
    this->mobile = mobile;
	this->id = id;
}

void Patient::setName(string name) {
    this->name = name;
}

void Patient::setBloodType(string setBloodType) {
    this->BloodType = BloodType;
}

void Patient::setMobile(string mobile) {
    this->mobile = mobile;
}

void Patient::setAge(int age) {
    this->age = age;
}

void Patient::setID(int id) {
	this->id = id;
}

void Patient::readData() {
    string name, bloodType, mobile; 
    int age, id;
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
	id++;
}

void Patient::printData() {
	cout << "Name: " << getName() << endl;
	cout << "Blood Type: " << getBloodType() << endl;
	cout << "Mobile: " << getMobile() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "ID: " << getID() << endl;
}

void AddEditData(vector<Patient>p) {
	int choice;
	int i = 0;
	bool ON = true;
	while(ON) {
		cout << "******************************************\n";
		cout << "To add a new patient's data enter <1>\n";
		cout << "To print the current patient's data enter <2>\n";
		cout << "To print all the patients' data in the system enter <3>\n";
		cout << "To return to the previous menu enter <4>\n";
		cin >> choice;
		switch (choice){
		case 1:
			p[i++].readData();
			break;

		case 2:
			p[i - 1].printData();
			break;

		case 3:
			for (int j = 0; j < i; j++) {
				cout << "**********************************\n";
				cout << "Patient #" << j + 1 << " data: \n";
				p[j].printData();
			}
			break;

		case 4:
			ON = false;
			break;
		
		default:
			cout << "please enter a valid choice\n";
			break;
		}
		
	}
}

int main() {
	string my_password;
	vector<Patient>p;
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
	char tester;
	do {
		cout << "\nto change your password ,| enter <C> |\n";
		cout << "to Search               ,| enter <S> |\n";
		cout << "to Add or edit data     ,| enter <A> |\n";
		cout << "to quit                 ,| enter <E> |\n";
		cin >> tester;
		if (tester == 'C' || tester == 'c')owner.set_newpassword();
		if (tester == 'A' || tester == 'a') AddEditData(p);
		if (tester == 'E' || tester == 'e')tester = 'e';
	} while (tester != 'e');  
}
