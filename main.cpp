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
};
int main() {
	int counter = 1;
	password owner;
	do {
		string my_password;
		if (counter > 1) {
			cout << "your password is wrong , please enter a correct password or the number < 0 > to quit: ";
			cin >> my_password;
			owner.set_password(my_password);
			if (my_password == "0")
				return 0;
			}
		
		if (counter == 1) {
		cout << "please enter a correct password: ";
		cin >> my_password;
		owner.set_password(my_password);
		counter++; }
	} while (owner.check_password());
}
