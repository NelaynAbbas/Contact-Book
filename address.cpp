#include "address.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

ostream& operator << (ostream& out, const Address& c)
{
    out << "\n\t\t\t\t   House No.        :    " << c.houseno;
    out << "\n\t\t\t\t   Street           :    " << c.street;
    out << "\n\t\t\t\t   City             :    " << c.city;
    return out;
}

istream& operator >> (istream& in, Address& c)
{
    cout << "\n\t\t\t\t**   Enter House No.     :    ";
    getline(in,c.houseno);
    cout << "\n\t\t\t\t**   Enter Street        :    ";
    getline(in,c.street);
    cout << "\n\t\t\t\t**   Enter City          :    ";
    getline(in,c.city);
    return in;
}

ofstream& operator << (ofstream& out, const Address& c) {
    out << c.houseno << endl << c.street << endl << c.city << endl;
    return out;
}

ifstream& operator >> (ifstream& in, Address& c) {
    in >> c.houseno >> c.street >> c.city;
    return in;
}