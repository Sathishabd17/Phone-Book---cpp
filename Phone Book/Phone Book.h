#include <iostream>
#include <fstream>
#include <string>
#include <iomanip.h>
#include <conio.h>
using namespace std;

	class phonebook
	{
		long long int contactno;
		string contactname;
		
		public:
			string getcontactname()
			{
				return contactname;
			}
			
			long long int getcontactno()
			{
				return contactno;
			}
			
			void storedata()
			{
					cout << ("\nName: ");
					getline(cin,contactname);
					
					cout << ("\nContact Number: ");
					cin >> contactno;
					fflush(stdin);
			}
	}p;

void Menu();
void AddContact();
void ListContact();
void DeleteContact();


