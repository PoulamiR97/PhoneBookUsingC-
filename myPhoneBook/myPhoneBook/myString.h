#include<iostream>
using namespace std;
#pragma once

class myString {
private:
	char* buffer{ nullptr };
	int64_t size;

public:
	myString();  // Default constructor
	myString(const char* str);  // Parameterized constructor
	myString(const myString& OtherStr); // Copy constructor
	myString(myString&& OtherStr) noexcept;  // Move constructor
	const myString& operator = (const myString& OtherStr); // Copy assignment operator
	myString& operator = (myString&& OtherStr) noexcept; // Move assignment operator
	friend ostream& operator << (ostream& os, myString& str);  // insertion operator overload
	friend istream& operator >> (istream& is, myString& str);  // extraction operator overload
	char& operator [] (int index);  // subscription operator overload
	friend bool operator == (const myString& str1, const myString& str2); // == operator overload
	int64_t getSize() const;   // Returns the size of the myString class object
	//bool erase() const;
	~myString();  // Destructor

};

