#include "contact.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

ostream& operator << (ostream& out, const Contact& c)
{
    out << "\n\t\t\t\t   First Name       :    " << c.f_name;
    out << "\n\t\t\t\t   Last Name        :    " << c.l_name;
    out << "\n\t\t\t\t   Mobile Number    :    " << c.mobile_no;
    out << "\n\t\t\t\t   Address          :    " << c.address << endl;
    return out;
}

istream& operator >> (istream& in, Contact& c)
{
    in.ignore();
    cout << "\n\t\t\t\t**   Enter First Name        :    ";
    getline(in, c.f_name);
    cout << "\n\t\t\t\t**   Enter Last Name         :    ";
    getline(in, c.l_name);
    cout << "\n\t\t\t\t**   Enter Mobile Number     :    ";
    getline(in, c.mobile_no);
    cout << "\n\t\t\t\t**   Enter Address           :    ";
    in >> c.address;
    return in;
}

ifstream& operator >> (ifstream& in, Contact& c) {
    in >> c.f_name >> c.l_name >> c.mobile_no;
    in >> c.address;
    return in;
}

ofstream& operator << (ofstream& out, Contact& c) {
    out << c.f_name << endl << c.l_name << endl << c.mobile_no << endl;
    out << c.address;
    return out;
}