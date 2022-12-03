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
	int counter = 0;
	password owner;
	string my_password;
	do {
		if (counter > 0) {
			cout << "your password is wrong to submit another one, please enter the number < 0 >: ";
			cin >> counter;
			if (counter != 0) {
				cout << "see you soon\n";
				return 0;
			}
		}
		cout << "please enter a correct password:\n";
		cin >> my_password;
		owner.set_password(my_password);
		counter++;
	} while (owner.check_password());
}
