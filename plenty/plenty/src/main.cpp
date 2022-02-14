#include "include\backend\LinkedList.h"
#include "include\backend\HistoryEventManager.h"

#include "include\backend\SaveManager.h"

#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

struct PROFILE
{
	string registerUsername, loginUsername;
};

void mainMenu()
{
	string eventName, eventDescription, eventDate;
	int choice;
	system("CLS");
	cout << "| ==================== |" << endl;
	cout << "|         MENU         |" << endl;
	cout << "| ==================== |" << endl;
	cout << "| 1. Add event" << endl;
	cout << "| 2. Remove event" << endl;
	cout << "| 3. See all events" << endl;
	cout << "| 4. Exit" << endl;
	cin >> choice;

	switch (choice) {
	case 1:
		//function for add event
		system("CLS");
		cout << "| Enter the name of event: ";
		cin >> eventName;


		cout << "| Enter the date of event: ";
		cin >> eventDate;


		cout << "| Enter the description of event: ";
		cin.ignore(INT_MAX, '\n');
		getline(cin, eventDescription);


		break;
	case 2:
		//function for remove event
		system("CLS");
		cout << "| Enter the name of event to be removed: ";
		cin >> eventName;
		cout << endl;
		break;
	case 3:
		system("CLS");
		//function for all events
		break;
	case 4:
		exit(0);
		break;
	default:
		cout << "Please, select valid comand." << endl;
		mainMenu();
		break;
	}
}

string hiddenPassword()
{

	string password;
	int i = 0;

	char a;
	for (i = 0;;)
	{
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
		{
			password += a;
			++i;
			cout << "*";
		}
		if (a == '\b' && i >= 1)//backspace and i should be greater than 1
		{
			cout << "\b \b";//delete the character behind the cursor
			--i;
		}
		if (a == '\r')//when enter is pressed 
		{
			return password;
		}
	}

}



int main()
{
	PROFILE firstUserRegistration;
	PROFILE firstUserLogin;

	string registerPassword, repeatedPassword, loginPassword;
	do
	{

		system("CLS");
		cout << "| =================== |" << endl;
		cout << "|    REGISTER MENU    |" << endl;
		cout << "| =================== |" << endl;
		cout << "| Username: ";
		cin >> firstUserRegistration.registerUsername;
		cout << "| Password: ";
		registerPassword = hiddenPassword();
		cout << "\n| Repeat password: ";
		repeatedPassword = hiddenPassword();
	} while (repeatedPassword != registerPassword);




	do
	{
		system("CLS");
		cout << "| ================== |" << endl;
		cout << "|     LOGIN MENU     |" << endl;
		cout << "| ================== |" << endl;
		cout << "| Username: ";
		cin >> firstUserLogin.loginUsername;
		cout << "| Password: ";
		loginPassword = hiddenPassword();


	} while (loginPassword != registerPassword);
	mainMenu();

}
