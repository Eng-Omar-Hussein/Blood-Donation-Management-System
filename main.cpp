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
	bool check_legitpassword(string password)
        {
   	bool haslower = false, hasupper = false, hasdigit = false, legitlenght=true;
   	for (int i = 0; i < password.length(); i++)
    		{
      		if (password.length() < 8)
      		{
        	legitlenght = false;
         	break;
      		}
      		if (islower(password[i]))
         	haslower = true;
      		if (isupper(password[i]))
         	hasupper = true;
      		if (isdigit(password[i]))
         	hasdigit = true;
    		}
    		if ( legitlenght && haslower && hasupper && hasdigit)
        	return true;
    		else
        	return false;
   	}
	void set_newpassword(void) {
		cout << "enter the old password: ";
		string z, p;
		do {
		cin >> z;
		if (z == y){
		while(true)
            	{
            	cout<<"enter the new password: ";
            	cin>>p;
            	if (check_legitpassword(p)){
             	cout<<"password has changed successfully\n";
             	y = p;
             	break;
            	}
            	else
             	cout<<"password should have at least 8 characters, 1 uppercase character, 1 lowercase character, and 1 digit\n";
             	continue;
            	}
        }
        if (z == "0" || check_legitpassword(p))
		break;
	cout << "please enter a correct password or < 0 > to quit: ";
	} while (z != x);
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
