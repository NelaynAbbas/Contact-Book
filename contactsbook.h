#ifndef CONTACTSBOOK_H
#define CONTACTSBOOK_H

#include"contact.h"
#include"group.h"

#include<string>
#include<iostream>
#include<fstream>


using namespace std;

class ContactBook {
	Contact* contacts;
	Contact* loadContacts;
	Group groups;
	int size, fill, loadTotal;
public:
	void mergeContacts();
	bool makeList(int num);
	bool addContact();
	void loadContact();
	void storeContact();
	bool search(string name);
	bool deleteContact(string name);
	void testPrint();
	void printUnsort();
	void printSort();
	void advanceSeacrh();
	void searchHistory();
	void addGroup();
	void deleteGroupContact();
	void deleteGroup();
	void totalContacts();
};


#endif // !CONTACTSBOOK_H