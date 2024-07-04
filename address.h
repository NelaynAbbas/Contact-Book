#ifndef ADDRESS_H
#define ADDRESS_H

#include<string>
#include<iostream>

using namespace std;

class Address {
	string houseno, street, city;
public:
	friend ostream& operator << (ostream& out, const Address& c);
	friend istream& operator >> (istream& in, Address& c);
	friend ofstream& operator << (ofstream& out, const Address& c);
	friend ifstream& operator >> (ifstream& in, Address& c);
};

#endif // !ADDRESS_H
