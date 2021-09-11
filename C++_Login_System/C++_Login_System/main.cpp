#include <iostream> // for outputting text
#include <fstream> // for writing and reading out files
#include <string> // for the string variable

using namespace std;

bool IsLoggedIn()
{
	string username, password, un, pw; // un and pw are comparison strings

	cout << "Enter username: "; cin >> username; // cin to input the username, that variable is saved and cout to display the username
	cout << "Enter password: "; cin >> password; // same thing but for the password

	ifstream read(username + ".txt");
	getline(read, un); // un comes first because username coems first
	getline(read, pw); // pw comes second because password comes second

	if (un == username && pw == password) // double & (&&) for both conditions to be true
	{
		return true;
	}
	else
	{
		return false;
	} 
}

int main() // main function
{
	int choice; // for the choice where we want to register for register function

	cout << "1: Register\n2: Login\nYour choice: "; cin >> choice;
	if (choice == 1)
	{
		string username, password;

		cout << "select a username: "; cin >> username;
		cout << "select a password: "; cin >> password;

		ofstream file; // ifstream reads files, ofstream creates files
		file.open( username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}
	else if (choice == 2)
	{
		bool status = IsLoggedIn(); // the "status" bool tells the program to do IsLoggedIn first

		if (!status)
		{
			cout << "False Login!" << endl;
			system("PAUSE");
			return 0; // we have to return to an int, and zero is an int
		}
		else
		{
			cout << "Successfully logged in!" << endl;
			system("PAUSE");
			return 1;
		}
	}
}