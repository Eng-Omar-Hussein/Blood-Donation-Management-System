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
	string Name, BloodType, Mobile, ID, Age;
public:
	void setName(string s) {
		Name = s;
	}
	void setBloodType(string s) {
		BloodType = s;
	}
	void setMobile(string s) {
		Mobile = s;
	}
	void setID(string s) {
		ID = s;
	}
	void setAge(string x) {
		Age = x;
	}
	string getName() {
		return Name;
	}
	string getBloodType() {
		return BloodType;
	}
	string getMobile() {
		return Mobile;
	}
	string getID() {
		return ID;
	}
	string getAge() {
		return Age;
	}
	Patient() {
		Name = "omar";
		BloodType = "o";
		Mobile = "01100226115";
		ID = "123456";
		Age = "20";
	}
};

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
		while (true) {
			getline(file, t);
			if (t.size()) (*p)++;
			else break;
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
			getline(file, temp);
			obj[i].setName(temp.substr(0, temp.find(",")));
			obj[i].setBloodType(temp.substr(temp.find(",") + 1, temp.find(";") - temp.find(",") - 1));
			obj[i].setMobile(temp.substr(temp.find(";") + 1, temp.find("/") - temp.find(";") - 1));
			obj[i].setID(temp.substr(temp.find("/") + 1, temp.find(":") - temp.find("/") - 1));
			obj[i].setAge(temp.substr(temp.find(":") + 1, temp.find(".") - temp.find(":") - 1));
		}
		file.close();
	}
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
void add_new(vector<Patient>& obj1, int* p) {
	string x1;
	cout << "Patient #" << *p + 1 << endl;;
	cout << "Name: ";
	cin >> x1;
	obj1[*p].setName(x1);
	cout << "BloodType: ";
	cin >> x1;
	obj1[*p].setBloodType(x1);
	cout << "Mobile: ";
	cin >> x1;
	obj1[*p].setMobile(x1);
	cout << "ID: ";
	cin >> x1;
	obj1[*p].setID(x1);
	cout << "Age: ";
	cin >> x1;
	obj1[*p].setAge(x1);
	(*p)++;
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
		if (tester == 'A' || tester == 'a') {
			add_new(obj, &num);
			app_data(obj, num);
		}
		if (tester == 'E' || tester == 'e');
		if (tester == 'Q' || tester == 'q')break;
	}
	return 0;
}
