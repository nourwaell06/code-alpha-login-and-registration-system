#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

class user {
private:
	string username;
	string pass;
public:
	user() {
		cout << "Welcome to login system" << endl;

	}

	void registeration() {
		cout << "Enter username : ";
		cin >> username;
		cout << "Enter password : ";
		cin >> pass;
		ofstream file("users.txt", ios::app);

		if (file.is_open())
		{
			file << username << " " << pass << endl;
			file.close();

			cout << "Account Created Successfully!" << endl;
		}
		else
		{
			cout << "Error Opening File!" << endl;
		}

	}
	void login() {

		string inputUser;
		string inputPass;
		string storedUser;
		string storedPass;

		bool found = false;

		cout << "Enter username : ";
		cin >> inputUser;
		cout << "Enter password : ";
		cin >> inputPass;

		ifstream file("users.txt");
		if (file.is_open())
		{
			while (file >> storedUser >> storedPass)
			{
				if (inputUser == storedUser &&
					inputPass == storedPass)
				{
					found = true;
					break;
				}
			}

			file.close();

			if (found)
			{
				cout << "Login Successful!" << endl;
				cout << "Welcome " << inputUser << endl;
			}
			else
			{
				cout << "Invalid Username or Password!" << endl;
			}
		}
		else
		{
			cout << "Error Opening File!" << endl;
		}

	}

	void menu() {

		int choice;
		do {
			cout << "login system " << endl;
			cout << "1 Register" << endl;
			cout << "2 Login" << endl;
			cout << "3 Exit" << endl;
			cout << "Enter your choice : ";
			cin >> choice;
			switch (choice) {
			case 1:
				registeration();
				break;
			case 2:
				login();
				break;
			case 3:
				cout << "Exiting..." << "thank you for using system" << endl;
				break;
			default:
				cout << "Invalid choice" << endl;

			}


		} while (choice != 3);

	}
};
int main() {
	user u;
	u.menu();
	return 0;

}