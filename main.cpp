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
    set_newpassword(void) {
	    cout<<"enter the old password: ";
	    string z,p;
	    do{
        cin>>z;
	    if (z == y)
        {
            cout<<"enter the new password: ";
            cin>>p;
            cout<<"password has changed successfully";
            y = p;
            break;
        }
        if (z == "0")
			break;
        cout<<"please enter a correct password or < 0 > to quit: ";
	    }while(z != x);
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

	owner.set_newpassword();
}
