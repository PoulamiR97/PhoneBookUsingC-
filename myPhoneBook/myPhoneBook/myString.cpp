#include<iostream>
#include "myString.h"
using namespace std;


myString::myString() :buffer{ nullptr }, size{ 0 }
{
}


myString::myString(const char* str) {
	size = strlen(str);
	buffer = new char[size + 1];
	memcpy(buffer, str, size);
	buffer[size] = '\0';  //setting last character as null of myString
}


myString::myString(const myString& OtherStr)
{
	this->size = OtherStr.size;
	this->buffer = new char[OtherStr.size + 1];
	memcpy(buffer, OtherStr.buffer, static_cast<int64_t>(size + 1));
	/*copy upto last char i.e.null char of myString that's why (size+1) ,
	static cast to restrict warning of overflow */
}


myString::myString(myString&& OtherStr) noexcept
{
	/* Transfer of ownership from temporary
	resources to original existing resources*/
	delete[] buffer;
	this->size = OtherStr.size;
	this->buffer = OtherStr.buffer;
	/* Releasing of temporary resources*/
	OtherStr.size = 0;
	OtherStr.buffer = nullptr;
}


const myString& myString::operator=(const myString& OtherStr)
{
	if (this != &OtherStr) {                                 // Checking of self-assignment
		this->size = OtherStr.size;
		this->buffer = new char[OtherStr.size + 1];
		memcpy(buffer, OtherStr.buffer, static_cast<int64_t>(size + 1));
		/*copy upto last char i.e.null char of myString that's why (size+1) ,
		static cast to restrict warning of overflow */
	}
	return *this;
}


myString& myString::operator=(myString&& OtherStr) noexcept
{
	if (this != &OtherStr) {                                 // Checking of self-assignment
		/* Transfer of ownership from temporary
		resources to original existing resources*/
		delete[] buffer;
		this->size = OtherStr.size;
		this->buffer = OtherStr.buffer;
		/* Releasing of temporary resources*/
		OtherStr.size = 0;
		OtherStr.buffer = nullptr;
	}
	return *this;
}


ostream& operator << (ostream& os, myString& str) {
	if (str.buffer) {
		int i = 0;
		while (i < str.size) {
			os << str.buffer[i];
			++i;
		}
	}
	return os;
}


istream& operator >> (istream& is, myString& str)
{
	char* temp;
	int temp_size(256);
	temp = new char[temp_size];
	is.getline(temp, temp_size);
	str = move(temp);
	return is;
}


char& myString::operator[] (int index)
{
	return buffer[index];
}

bool operator == (const myString& str1, const myString& str2)
{
	if (str1.size != str2.size) 
		return false;
	for (int i = 0; i <= str1.size; i++) {
		if(str1.buffer[i] != str2.buffer[i])
		return false;
	}
		return true;
}


int64_t myString::getSize() const
{
	return this->size;
}

//bool myString::erase() const
//{
//	for (int i = 0; i <= this->size; i++) {
//		this->buffer[i] = ' ';
//	}
//
//	if (this->getSize() == 0)
//		return true;
//	else
//		return false;
//}


myString::~myString() {
	delete[] buffer;
	buffer = nullptr;
	size = 0;
}
