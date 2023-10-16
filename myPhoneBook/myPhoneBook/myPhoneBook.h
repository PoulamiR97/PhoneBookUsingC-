#include<iostream>
#include <vector>
#include"myString.h"
#include"myDetails.h"

using namespace std;
#pragma once

class myPhoneBook {
	private:
		vector <myDetails> phBkVec{};

	public:
		myPhoneBook();              // Default constructor
		void addNewContact();       // To add a new contact
		bool searchByPhNo();        // To search a contact by phone number
		bool searchByName();        // To search a contact by name
		void displayContactList();  // To display entire contact list
		void modifyContact();       // To modify a contact by phone number or by name
		void deleteContact();       // To delete a contact by phone number or by name
};