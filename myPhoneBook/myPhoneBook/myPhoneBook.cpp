#include<iostream>
#include <vector>
#include"myString.h"
#include"myDetails.h"
#include"myPhoneBook.h"

using namespace std;

static int64_t index{ 0 };

myPhoneBook::myPhoneBook() 
{

}


void myPhoneBook::addNewContact()
{
	cout << "\n*** ADDING NEW CONTACT ***\n";

	myString name, number, mail;
	cout << "Enter new name to be added: ";
	cin.ignore();
	cin >> name;
	for (auto& x_name : phBkVec) {
		if (x_name.getName() == name )
			throw (myString)"\nEntered name already exists! \n";
	}
	cout << "Enter corresponding mobile number to be added: ";
	cin >> number;
	cout << "Enter corresponding email id to be added: ";
	cin >> mail;
	phBkVec.emplace_back(name, number, mail);
	for (auto& x_name : phBkVec) {
		x_name.setName(name);
		x_name.setPhNo(number);
		x_name.setMailId(mail);
	}
	cout << "\nContact added and saved successfully! \n" << endl;
}


bool myPhoneBook::searchByPhNo() 
{
	if (phBkVec.empty() == true)
		throw (myString) "\nPhoneBook is empty! \n";

	cout << "\n*** SEARCHING PHONE NUMBER ***\n";

	myString number{ " " };
	cout << "Enter the number you want to search: ";
	cin.ignore();
	cin >> number;
	vector<myDetails>::iterator it;
	for (it = phBkVec.begin(); it != phBkVec.end(); it++) {
		if ( (*it).getPhNo()  == number) {
			index = it - phBkVec.begin();          // modifying value of index (a variable required in delete and modify contact functions)
			cout << number << " found! \n";
			return true;
		}
	}
	cout << number << " not found! \n" << endl;
	return false;
}


bool  myPhoneBook::searchByName() 
{
	if (phBkVec.empty() == true)
		throw (myString)"\nPhoneBook is empty! \n";

	cout << "\n*** SEARCHING NAME ***\n";

	myString name{" "};
	cout << "Enter the name you want to search: ";
	cin.ignore();
	cin >> name;
	vector<myDetails>::iterator it;   
	for (it = phBkVec.begin(); it != phBkVec.end(); it++) {
		if ( (*it).getName()  == name) {
			index = it - phBkVec.begin();           // modifying value of index (a variable required in delete and modify contact functions)
			cout << name << " found! \n";
			return true;
		}
	}
	cout << name << " not found! \n" << endl;
	return false;
}


void myPhoneBook::deleteContact()
{
	if (phBkVec.empty() == true)
		throw (myString)"\nPhoneBook is empty! \n";

	cout << "\n*** DELETING CONTACT ***\n";

	cout << "To delete contact Press 1. To search by name or  Press 2. To search by number : ";
	int choice{ 0 };
	cin.ignore();
	cin >> choice;
	//bool flag{ 0 };
		switch (choice) {
		case 1:
			cout << "\n*** Deleting by name ***\n";
			if (searchByName() == true ) {
				vector<myDetails>::iterator it = phBkVec.begin() + index;
				myString nameToBeDel = (*it).getName();
				phBkVec.erase(it);
				cout << nameToBeDel << " successfully deleted! \n" << endl;
				}
			break;

		case 2:
			cout << "\n*** Deleting by number ***\n";
			if (searchByPhNo() == true) {
				vector<myDetails>::iterator it = phBkVec.begin() + index;
				myString numToBeDel = (*it).getPhNo();
				phBkVec.erase(it);
				cout << numToBeDel << " successfully deleted! \n"  << endl;
			}
			break;
		default:
			cout << "\nInvalid Input! \n";
		}
}


void myPhoneBook::modifyContact()
{
	if (phBkVec.empty() == true)
		throw (myString)"\nPhoneBook is empty! \n";

	cout << "\n*** MODIFYING CONTACT ***\n";

	cout << "\nPress 1. : To modify name  || Press 2. To modify number : ";
	int choice{ 0 };
	cin.ignore();
	cin >> choice;
	//bool flag{ 0 };
	switch (choice) {
	case 1:
		//flag = searchByName();
		cout << "\n*** Modifying name ***\n";
		if (searchByName() == true) {
			myString newName;
			cout << "Enter the new name: ";
			cin >> newName;
			vector<myDetails>::iterator it = phBkVec.begin() + index;
			(*it).setName(newName);
			cout << newName << " successfully modified! \n" << endl;
		}
		break;

	case 2:
		//flag = searchByPhNo();
		cout << "\n*** Modifying number ***\n";
		if (searchByPhNo() == true) {
			myString newNum;
			cout << "Enter the new number: ";
			cin >> newNum;
			vector<myDetails>::iterator it = phBkVec.begin() + index;
			(*it).setPhNo(newNum);
			cout << newNum << " successfully modified! \n" << endl;
		}
		break;
	default:
		cout << "\n Invalid Input! \n";
	}
}


void myPhoneBook::displayContactList()
{	
	if (phBkVec.empty() == true)
		throw (myString)"\nPhoneBook is empty! \n";

	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                       CONTACT DETAIL LIST                                              " << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	int i = 1;
	vector<myDetails>::iterator it = phBkVec.begin();
	for (it = phBkVec.begin(); it != phBkVec.end(); it++) {
		myString name, phNo, email;
		name = (*it).getName(), phNo = (*it).getPhNo(), email = (*it).getMailId();
		cout << i << ". " << name << " || " << phNo << " || " << email << " ||" << endl;
		++i;
	}
	cout << endl;
}
