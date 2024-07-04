#include"contactsbook.h"

#include<iostream>

using namespace std;

int main() {
	ContactBook cb;
	int inp;
	do {
		cout << "\t\t\t\t*****************************************\n";
		cout << "\t\t\t\t*****************************************\n";
		cout << "\t\t\t\t**                                     **\n";
		cout << "\t\t\t\t**  Enter to Select an Option          **\n";
		cout << "\t\t\t\t**                                     **\n";
		cout << "\t\t\t\t**  1.  Load Contacts                  **\n";
		cout << "\t\t\t\t**  2.  Save Contacts                  **\n";
		cout << "\t\t\t\t**  3.  Merge Contacts                 **\n";
		cout << "\t\t\t\t**  4.  Make List                      **\n";
		cout << "\t\t\t\t**  5.  Add Contact                    **\n";
		cout << "\t\t\t\t**  6.  Delete Contact                 **\n";
		cout << "\t\t\t\t**  7.  Print Unsorted Contacts        **\n";
		cout << "\t\t\t\t**  8.  Print sorted Contacts          **\n";
		cout << "\t\t\t\t**  9.  Dispay Search History          **\n";
		cout << "\t\t\t\t**  10. Advance Search Contacts        **\n";
		cout << "\t\t\t\t**  11. Add Group                      **\n";
		cout << "\t\t\t\t**  12. Delete Contact From Group      **\n";
		cout << "\t\t\t\t**  13. Delete Group                   **\n";
		cout << "\t\t\t\t**  14. Display Contact Count          **\n";
		cout << "\t\t\t\t**  15. Exit                           **\n";
		cout << "\t\t\t\t**                                     **\n";
		cout << "\t\t\t\t*****************************************\n";
		cout << "\t\t\t\t*****************************************\n";
		cout << "\t\t\t\t**                                     **\n";
		cout << "\t\t\t\t**  Enter Choice   :   ";
		cin >> inp;
		cout << "\t\t\t\t*****************************************\n";
		if (inp == 1) {
			cb.loadContact();
			cout << "\t\t\t\t*****************************************\n";
			cout << "\t\t\t\t**                                     **\n";
			cout << "\t\t\t\t**    ALL CONTACTS FROM FILE LOADED    **\n";
			cout << "\t\t\t\t**                                     **\n";
			cout << "\t\t\t\t*****************************************\n";
		}
		else if (inp == 2) {
			cb.storeContact();
			cout << "\t\t\t\t*****************************************\n";
			cout << "\t\t\t\t**                                     **\n";
			cout << "\t\t\t\t**     ALL CONTACTS SAVED TO FILE      **\n";
			cout << "\t\t\t\t**                                     **\n";
			cout << "\t\t\t\t*****************************************\n";
		}
		else if (inp == 3) {
			cb.mergeContacts();
		}
		else if (inp == 4) {
			int num;
			cout << "\t\t\t\t*****************************************\n";
			cout << "\t\t\t\t**                                     **\n";
			cout << "\t\t\t\t**   Enter Size of the List  :  ";
			cin >> num;
			cb.makeList(num);
			cout << "\t\t\t\t**       LIST MADE OF GIVEN SIZE       **\n";
			cout << "\t\t\t\t**                                     **\n";
			cout << "\t\t\t\t*****************************************\n";
		}
		else if (inp == 5) {
			if (cb.addContact()) {
				cout << "\t\t\t\t*****************************************\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t**            CONTACT ADDED            **\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t*****************************************\n";
			}
			else {

				cout << "\t\t\t\t*****************************************\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t**          CONTACT NOT ADDED          **\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t*****************************************\n";
			}
		}
		else if (inp == 6) {
			string inp2;
			cout << "\t\t\t\t*****************************************\n";
			cout << "\t\t\t\t**                                     **\n";
			cout << "\t\t\t\t**   Enter Size of the List  :  ";
			cin >> inp2;
			cb.loadContact();
			if (cb.deleteContact(inp2))
			{
				cout << "\t\t\t\t**           CONTACT DELETED           **\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t*****************************************\n";
			}
			else {
				cout << "\t\t\t\t**         CONTACT NOT DELETED         **\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t*****************************************\n";
			}
		}
		else if (inp == 7) {
			cb.printUnsort();
		}
		else if (inp == 8) {
			cb.printSort();
		}
		else if (inp == 9) {
			cb.searchHistory();
		}
		else if (inp == 10) {
			cb.advanceSeacrh();
		}
		else if (inp == 11) {
			cb.addGroup();
		}
		else if (inp == 12) {
			cb.deleteGroupContact();
		}
		else if (inp == 13) {
			cb.deleteGroup();
		}
		else if (inp == 14) {
			cb.totalContacts();
		}
		cout << "\t\t\t\t*****************************************\n";
	} while (inp != 15);
	
	system("pause");
	return 0;
}