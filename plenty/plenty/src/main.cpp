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
void inputEvent(HistoryEventManager& HEM)
{
	string title, description, date;
	cout << "Enter event name: ";
	getline(cin, title);
	cout << "Enter event date: ";
	getline(cin, date);
	cout << "Enter event description: ";
	getline(cin, description);

	HEM.addEvent(HistoryEvent(title, description, date));
}

void deleteEvent(HistoryEventManager& HEM)
{
	string title, description, date;
	cout << "Enter event name: ";
	getline(cin, title);
	cout << "Enter event date: ";
	getline(cin, date);
	cout << "Enter event description: ";
	getline(cin, description);

	HEM.deleteEvent(HistoryEvent(title, description, date));
}

void showAllEvents(HistoryEventManager& HEM)
{
	LinkedList<HistoryEvent> events = HEM.getAll();
	Node head = events.getHead();
	while (head != NULL)
	{
		HistoryEvent data = head->getData();
		cout << "Event title: " << data.title << endl;
		cout << "Event date: " << data.date << endl;
		cout << "Event description: " << data.description << endl;
		head = head->getNext();
	}
}

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

		inputEvent();

		break;
	case 2:

		deleteEvent();

		break;
	case 3:
	
		showAllEvents();

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
	HistoryEventManager HEM;

	HistoryEvent HE;
	HEM.addEvent(HE);

	/*LinkedList<HistoryEvent> events = HEM.getAll();
	Node head = events.getHead();
	while (head != NULL)
	{
		HistoryEvent data = head->getData();
		cout << "Event title: " << data.title << endl;
		cout << "Event date: " << data.date << endl;
		cout << "Event description: " << data.description << endl;
		head = head->getNext();
	}*/

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
