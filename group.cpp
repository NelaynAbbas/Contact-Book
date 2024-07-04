#include "group.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

istream& operator >> (istream& in, Group& c) {
    in.ignore();
    cout << "\n\t\t\t\t**   Enter Group Name                :    ";
    getline(in, c.name);
    cout << "\n\t\t\t\t**   Enter Number of Participants    :    ";
    in >> c.tot;
    c.participants = new string[c.tot];

    in.ignore();

    for (int i = 0; i < c.tot; i++) {
        cout << "\n\t\t\t\t**   Enter Participant Name          :    ";
        getline(in, c.participants[i]);
    }

    ofstream out;

    out.open("groups.txt",ios::app);

    out << c.name << endl << c.tot << endl;
    for (int i = 0; i < c.tot; i++) {
        out << c.participants[i] << endl;
    }
    out.close();

    int totalGroup;
    ifstream inn;
    inn.open("groupCount.txt");
    inn >> totalGroup;
    inn.close();

    totalGroup++;

    out.open("groupCount.txt");
    out << totalGroup;
    out.close();

    return in;
}

ifstream& operator >> (ifstream& in, Group& c) {
    in >> c.name >> c.tot;
    for (int i = 0; i < c.tot; i++) {
        in >> c.participants[i];
    }
    return in;
}