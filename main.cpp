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
	void set_newpassword(string p) {
		y=p;
	}
};
int main() {
	string my_password;
	password owner;
	do {

		cout << "please enter a correct password or < 0 > to quit: ";
		cin >> my_password;
		owner.set_password(my_password);
		if (my_password == "0")
                return 0;

	} while (owner.check_password());
	owner.set_newpassword("1234567890");
}
