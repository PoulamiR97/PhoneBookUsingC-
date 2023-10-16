#include<iostream>
#include"myString.h"
using namespace std;
#pragma once

class myDetails {
private:
	myString m_Name;
	myString m_PhNo;
	myString m_MailId;

public:
	myDetails();  // Default constructor
	myDetails(myString o_Name, myString o_PhNo, myString o_MailId); // Parametrized constructor
	bool setName(myString& o_Name);      //set Name 
	bool setPhNo(myString& o_PhNo);      // set Phone Number
	bool setMailId(myString& o_MailId);  // set Email Id
	myString getName() const;            // returns the Name of myDetails object
	myString getPhNo() const;            // returns the phone number of myDetails object
	myString getMailId() const;          // returns the mail Id of myDetails object
	void display();                      // displays name, phone number, email Id
};