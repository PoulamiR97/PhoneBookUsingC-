#include <iostream>
#include"myDetails.h" 
#include "myString.h"

using namespace std;

myDetails::myDetails() : m_Name{" "}, m_PhNo{" "}, m_MailId{" "}
{
}

myDetails::myDetails(myString o_Name, myString o_PhNo, myString o_MailId) : m_Name{ o_Name }, m_PhNo{ o_PhNo }, m_MailId{ o_MailId }
{

}

bool myDetails::setName(myString& o_Name)
{
    //myString strError{ "Unable to set Name" };

    if (o_Name == "") {             // if blank string return false
        throw (myString)  "\nUnable to set Name! Please enter a valid name!\n" ;
        //return false;
    }
   
    for (int i = 0; i < o_Name.getSize(); ++i) {             // if string contains any character except alphabets return false
        if (!( (o_Name[i] >= 'a' && o_Name[i] <= 'z') || (o_Name[i] >= 'A' && o_Name[i] <= 'Z') || isspace(o_Name[i]) )) {
        throw (myString) "\nUnable to set Name! Please use alphabets only!\n";
        //return false;
        }
    }
    this->m_Name = o_Name;
    cout << "Name: " << m_Name << " successfully set!\n" << endl;
    return true;
}

bool myDetails::setPhNo(myString& o_PhNo)
{
    //myString strError{ "Unable to set Phone Number" };

    if (o_PhNo == "" || o_PhNo.getSize() < 10) {             // if blank string return false
        throw (myString) "\nUnable to set Phone Number! Please enter a valid 10 digit number! \n";
        //return false;
    }

    for (int i = 0; i < o_PhNo.getSize(); ++i) {             // if string contains any character except digits return false
        if ((!(o_PhNo[i] >= '0' && o_PhNo[i] <= '9'))|| isspace(o_PhNo[i])) {
            throw (myString)"\nUnable to set Phone Number! Please use digits only! \n";
            //return false;
        }
    }
    this->m_PhNo = o_PhNo;
    cout << "Phone number: " << m_PhNo << " successfully set!" << endl;
    return true;
}

bool myDetails::setMailId(myString& o_MailId)
{
    if (o_MailId == "")              // if blank string return false
        throw (myString) "\n Unable to set Email Id! Please enter valid email id! \n";
        //return false;

    for (int i = 0; i < o_MailId.getSize(); ++i) {             // email id do not contain any space character
        if (isspace(o_MailId[i]) )
            throw (myString)"\n Unable to set Email Id as it contain space! Please enter valid email id! \n";
        //return false;
    }
    
    this->m_MailId = o_MailId;
    cout << "Email: " << m_MailId << " successfully set!" << endl;
    return true;
    
}

myString myDetails::getName() const
{
	return this->m_Name;
}

myString myDetails::getPhNo() const
{
	return this->m_PhNo;
}

myString myDetails::getMailId() const
{
	return this->m_MailId;
}

void myDetails::display()
{
    myString name, num, mail;
    name = getName();
    num = getPhNo();
    mail = getMailId();
    cout << "Name: " << name << ", Ph No : " << num << ", Mail: " << mail << endl;
}
