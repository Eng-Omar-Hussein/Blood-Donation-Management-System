#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Patient {
    private:
        string name, BloodType, mobile;
        int age;
    public:
        // constructors
        Patient() {}
        Patient(string name, string bloodType, int age, string mobile);
        // setters
        void setName(string name);
        void setBloodType(string setBloodType);
        void setAge(int age);
        void setMobile(string mobile);
        // getters
        string getName() { return name; }
        string getBloodType() { return BloodType; }
        string getMobile() { return mobile; }
        int getAge() { return age; } 
        // other functions
        void readData();
};

Patient::Patient(string name, string bloodType, int age, string mobile) {
    this->name = name;
    this->BloodType = bloodType;
    this->age = age;
    this->mobile = mobile;
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

void Patient::readData() {
    string name, bloodType, mobile; 
    int age;
    cout << "Please enter the patient's data: \n";
    cout << "Name: ";
    getline(cin, name); setName(name);
    cout << "Blood Type: ";
    cin >> BloodType; setBloodType(bloodType);
    cout << "Mobile: ";
    cin >> mobile; setMobile(mobile);
    cout << "Age: ";
    cin >> age; setAge(age);
    cout << endl;
}


class password {
private:
	string x,y;
public:
    password(void)
    {
        fstream file;
        file.open("password.txt", ios::in);
        if (file.is_open())
        {
        getline(file, y);
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
                    if (file.is_open()){
                    file<<new_passwor;
                    file.close();
                    }
                    y = new_passwor;
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
int main() {
	string my_password;
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
		//if (tester == 'A' || tester == 'a')Write here;
		if (tester == 'E' || tester == 'e')tester = 'e';
	} while (tester != 'e');
    }
