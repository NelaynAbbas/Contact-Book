#include "contactsbook.h"

#include<string>
#include<iostream>
#include<fstream>
#include <ctime>

using namespace std;

string getCurrentDateTimeString() {
	time_t now = time(0);
	struct tm timeinfo;
	char buffer[80];
	#ifdef _WIN32
		localtime_s(&timeinfo, &now);
	#else
		localtime_r(&now, &timeinfo);
	#endif
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
	return std::string(buffer);
}

bool ContactBook::makeList(int num) {
	if (num < 1)
		return false;
	size = num;
	fill = 0;

	contacts = new Contact[size];
	return true;
}

bool ContactBook::addContact() {
	if (fill == size)
		return false;
	cin >> contacts[fill];
	fill++;
}
void ContactBook::loadContact() {
	ifstream in;
	in.open("contactsCount.txt");
	in >> loadTotal;
	in.close();

	loadContacts = new Contact[loadTotal];

	in.open("contacts.txt");

	for (int i = 0; i < loadTotal; i++) {
		in >> loadContacts[i];
	}
}

void ContactBook::storeContact() {
	ifstream in;
	in.open("contactsCount.txt");
	in >> loadTotal;
	in.close();

	ofstream out;
	out.open("contacts.txt", ios::app);

	for (int i = 0; i < fill; i++) {
		loadTotal++;
		out << contacts[i];
	}

	out.close();

	out.open("contactsCount.txt");
	out << loadTotal;
	out.close();
}

void ContactBook::testPrint() {
	for (int i = 0; i < loadTotal; i++) {
		cout << loadContacts[i];
	}
}

bool ContactBook::search(string name) {
	for (int i = 0; i < loadTotal; i++) {
		if (loadContacts[i].f_name == name || loadContacts[i].l_name == name)
			return true;
	}
	return false;
}

bool ContactBook::deleteContact(string name) {
	if (!search(name))
		return false;
	for (int i = 0; i < loadTotal; i++) {
		if (loadContacts[i].f_name == name || loadContacts[i].l_name == name)
			loadContacts[i].f_name = "-";
	}
	
	ifstream in;
	in.open("contactsCount.txt");
	in >> loadTotal;
	in.close();

	ofstream out;
	out.open("contacts.txt");

	for (int i = 0; i < loadTotal; i++) {
		if (loadContacts[i].f_name != "-")
			out << loadContacts[i];
	}
	
	out.close();

	loadTotal--;

	out.open("contactsCount.txt");
	out << loadTotal;
	out.close();

	loadContact();
}

void ContactBook::printUnsort() {
	cout << "\t\t\t\t*****************************************\n";
	cout << "\t\t\t\t**                                     **\n";
	cout << "\t\t\t\t**             ALL CONTACTS            **\n";
	cout << "\t\t\t\t**                                     **\n";
	cout << "\t\t\t\t*****************************************\n";

	for (int i = 0; i < loadTotal; i++) {
		cout << "\t\t\t\t*****************************************\n";
		cout << "\t\t\t\t              Contact No. " << i + 1 << endl << endl;

		cout << loadContacts[i];
		cout << "\t\t\t\t*****************************************\n";
	}
}

void ContactBook::printSort() {
	Contact* sortList = new Contact[loadTotal];
	for (int i = 0; i < loadTotal; i++) {
		sortList[i] = loadContacts[i];
	}

	Contact temp;

	for (int i = 0; i < loadTotal - 1; i++) {
		for (int j = i + 1; j < loadTotal; j++) {
			if (sortList[i].f_name > sortList[j].f_name) {
				temp = sortList[i];
				sortList[i] = sortList[j];
				sortList[j] = temp;
			}
		}
	}

	cout << "\t\t\t\t*****************************************\n";
	cout << "\t\t\t\t**                                     **\n";
	cout << "\t\t\t\t**             ALL CONTACTS            **\n";
	cout << "\t\t\t\t**                                     **\n";
	cout << "\t\t\t\t*****************************************\n";

	for (int i = 0; i < loadTotal; i++) {
		cout << "\t\t\t\t*****************************************\n";
		cout << "\t\t\t\t              Contact No. " << i + 1 << endl << endl;

		cout << sortList[i];
		cout << "\t\t\t\t*****************************************\n";
	}
}

void ContactBook::mergeContacts() {
	for (int i = 0; i < loadTotal - 1; i++) {
		for (int j = i + 1; j < loadTotal; j++) {
			if (loadContacts[i].f_name == loadContacts[j].f_name && loadContacts[i].l_name == loadContacts[j].l_name && loadContacts[i].mobile_no == loadContacts[j].mobile_no) {
				loadContacts[i].f_name = "-";
			}
		}
	}

	ofstream out;
	out.open("contacts.txt");

	for (int i = 0; i < loadTotal; i++) {
		if (loadContacts[i].f_name != "-")
			out << loadContacts[i];
	}
	
	out.close();

	loadTotal--;

	out.open("contactsCount.txt");
	out << loadTotal;
	out.close();

	loadContact();
}

void ContactBook::advanceSeacrh() {
	string str;
	cout << "\t\t\t\t**   Enter String to Serach Contact  :  ";
	cin >> str;

	string currentDateTime = getCurrentDateTimeString();

	ofstream out;
	out.open("searchhistory.txt",ios::app);

	out << str << "\t" << currentDateTime << endl;
	out.close();

	bool flag = false;
	int index = 0;

	for (int i = 0; i < loadTotal; i++) {
		flag = false;
		for (int j = 0; j < loadContacts[i].f_name.length() && index < str.length(); j++) {
			if (str[index] == loadContacts[i].f_name[j])
				index++;
		}
		if (index == str.length())
			flag = true;
		index = 0;


		for (int j = 0; j < loadContacts[i].l_name.length() && index < str.length(); j++) {
			if (str[index] == loadContacts[i].l_name[j])
				index++;
		}
		if (index >= str.length())
			flag = true;
		index = 0;

		for (int j = 0; j < loadContacts[i].mobile_no.length() && index < str.length(); j++) {
			if (str[index] == loadContacts[i].mobile_no[j])
				index++;
		}
		if (index == str.length())
			flag = true;
		
		if (flag) {
			cout << "\t\t\t\t*****************************************\n";
			cout << "\t\t\t\t              Contact No. " << i + 1 << endl << endl;

			cout << loadContacts[i];
			cout << "\t\t\t\t*****************************************\n";
		}

	}
}

void ContactBook::searchHistory() {
	ifstream in;
	in.open("searchhistory.txt");

	string str;

	while (!in.eof()) {
		getline(in,str);
		if (!in.eof()) {
			cout << "\t\t\t\t    " << str << endl;;
		}
	}
}

void ContactBook::addGroup() {
	cin >> groups;
}

void ContactBook::deleteGroupContact() {
	string str;
	cout << "\t\t\t\t**   Enter First Name of Contact     :  ";
	cin >> str;

	int totalG;

	ifstream in;
	in.open("groupCount.txt");
	in >> totalG;
	in.close();

	Group* gg = new Group[totalG];

	in.open("groups.txt");
	for (int i = 0; i < totalG; i++) {
		in >> gg[i];
	}
	in.close();

	ofstream out;
	out.open("groups.txt");
	for (int i = 0; i < totalG; i++)
	{
		out << gg[i].name << endl << gg[i].tot << endl;
		for (int j = 0; i < gg[i].tot; j++) {
			if (gg[i].participants[j] != str)
				out << gg[i].participants[j] << endl;
		}
	}
	out.close();
}

void ContactBook::deleteGroup() {
	string str;
	cout << "\t\t\t\t**   Enter Name of the Group         :  ";
	cin >> str;

	int totalG;

	ifstream in;
	in.open("groupCount.txt");
	in >> totalG;
	in.close();

	Group* gg = new Group[totalG];

	in.open("groups.txt");
	for (int i = 0; i < totalG; i++) {
		in >> gg[i];
	}

	in.close();

	ofstream out;
	out.open("groups.txt");
	for (int i = 0; i < totalG; i++)
	{
		if (gg[i].name != str) {
			out << gg[i].name << endl << gg[i].tot << endl;
			for (int j = 0; i < gg[i].tot; j++) {
				out << gg[i].participants[j] << endl;
			}
		}
	}
	out.close();

	out.open("groupCount.txt");
	out << --totalG;
	out.close();
}

void ContactBook::totalContacts() {
	ifstream in;
	in.open("contactsCount.txt");
	in >> loadTotal;
	in.close();

	cout << "\t\t\t\t**   Total Contacts               :  " << loadTotal << endl;
}