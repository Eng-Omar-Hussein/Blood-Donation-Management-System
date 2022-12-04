#include<iostream>
#include<string>
using namespace std;
class password {
private:
	string x, y = "123456789";
public:
	void set_password(string p) {
		x = p;
	}
	bool check_password() {
		if (x == y) return false;
		return true;
	}
	bool check_legitpassword(string password) {
		bool haslower = true, hasupper = true, hasdigit = true, legitlenght = false;
		for (int i = 0; i < password.length(); i++) {
			if (password.length() < 8) {
				legitlenght = true;
				break;
			}
			if (islower(password[i]))
				haslower = false;
			if (isupper(password[i]))
				hasupper = false;
			if (isdigit(password[i]))
				hasdigit = false;
		}

		if (legitlenght)
			cout << "your password must have at least <8> digits.\n";
		else if (haslower)
			cout << "your password must have at least <1> lowercase character.\n";
		else if (hasupper)
			cout << "your password must have at least <1> uppercase character.\n";
		else if (hasdigit)
			cout << "your password must have at least <1> digit character.\n";
		if (legitlenght || haslower || hasupper || hasdigit)
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
				cout << "please enter a new password or < 0 > to back : ";
				while (true) {

					cin >> new_passwor;
					if (new_passwor != "0" && check_legitpassword(new_passwor)) {
						cout << "password has changed successfully\n";
						y = new_passwor;
						break;
					}
					else if (new_passwor == "0")break;
					else cout << "please enter a new password (but there are Constraints) or < 0 > to back : ";
				}
			}
			else if (z != "0" && z != y) cout << "please enter a correct password or < 0 > to back: ";
		} while (z != x && z != "0");
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
		cout << "to Add or edite data    ,| enter <A> |\n";
		cout << "to quit                 ,| enter <E> |\n";
		cin >> tester;
		if (tester == 'C' || tester == 'c')owner.set_newpassword();
		if (tester == 'E' || tester == 'e')tester = 'e';
	} while (tester != 'e');
}
