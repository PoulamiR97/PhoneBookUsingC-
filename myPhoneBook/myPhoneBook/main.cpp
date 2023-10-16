#include<iostream>
#include"myString.h"
#include"myDetails.h"
#include"myPhoneBook.h"


using namespace std;

int main() {

    myPhoneBook myContact;
    int myChoice{0};
    bool error = false;

    try {
        do 
        {
                error = false;
                cout << "\n***********************************\n";
                cout << "\n  PHONEBOOK PROJECT - POULAMI RAHA \n";
                cout << "\n***********************************\n";
                cout << "(1) Add New Contact\n";
                cout << "(2) Search by Phone Number\n";
                cout << "(3) Search by Name\n";
                cout << "(4) Modify a contact\n";
                cout << "(5) Delete a contact \n";
                cout << "(6) Display Entire Contact List\n";
                cout << "(7) Exit\n";
                cout << "Choose your choice (any digit) : ";
                cin >> myChoice;

                switch (myChoice)
                {
                case 1:
                    myContact.addNewContact();
                   
                    break;

                case 2:
                    myContact.searchByPhNo();
                    break;

                case 3:
                    myContact.searchByName();
                    break;

                case 4:
                    myContact.modifyContact();
                    break;

                case 5:
                    myContact.deleteContact();
                    break;

                case 6:
                    myContact.displayContactList();
                    break;

                case 7:
                    cout << "\n*** THANK YOU! ***\n" << endl;
                    exit (0);

                default:
                    cout << "\nInvalid Entry!! \nPlease try again\n" << endl;
                    error = true;
                }
                 
        } while (error || 1);
    }

    catch (myString& ex) {
        cout << ex << endl;
    }

    catch (...) {
        cout << "\nException catched!!!!!!!!!!\n" << endl;
    }
    return 0;
}	