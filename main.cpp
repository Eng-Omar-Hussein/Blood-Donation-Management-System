#include<iostream>
#include<string>
using namespace std;
class password {
private:
	string x, y = "123456789";
public:
	void set_password(string p) { x = p;}
	bool check_password() 
	{
		if (x == y) return false;
		return true;
	}
};
int main() 
{
	password owner;
	for (int counter = 1;owner.check_password()== true;counter++)
        {
        string my_password;
		if (counter > 1)
        	{
		cout << "your password is wrong please enter a correct password or to quit the program enter < 0 > : ";
		cin >> my_password;
                owner.set_password(my_password);
			if (my_password == "0")
				counter=0;
			if (counter == 0)
            		{
				cout << "see you soon\n";
				break;
			}
		}
		if (counter == 1)
        	{
        	cout << "please enter a correct password:\n";
		cin >> my_password;
		owner.set_password(my_password);
        	}
	}
}
