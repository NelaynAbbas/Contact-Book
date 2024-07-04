#ifndef GROUP_H
#define GROUP_H

#include"contact.h"

#include<string>
#include<iostream>

using namespace std;

class Group {
	int tot;
	string name;
	string *participants;
	friend class ContactBook;
public:
	friend istream& operator >> (istream& in, Group& c);
	friend ifstream& operator >> (ifstream& in, Group& c);
};

#endif // !GROUP_H