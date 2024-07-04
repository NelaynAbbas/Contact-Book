#ifndef CONTACT_H
#define CONTACT_H

#include"address.h"

#include<string>
#include<iostream>

using namespace std;

class Contact {
	string f_name, l_name, mobile_no;
	Address address;
	friend class ContactBook;
	friend class Group;

public:
	friend ostream& operator << (ostream& out, const Contact& c);
	friend istream& operator >> (istream& in, Contact& c);
	friend ifstream& operator >> (ifstream& in, Contact& c);
	friend ofstream& operator << (ofstream& out, Contact& c);
	friend istream& operator >> (istream& in, Group& c);
};


#endif // !CONTACT_H
