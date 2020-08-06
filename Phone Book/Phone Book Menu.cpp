#include "Phone Book.h"
char filename[] = "Phone Book.txt";

int main()
{
	Menu();
	return 0;
}

void Menu()
{
	int opt;
	while(1)
	{
		system("cls");
		cout << ("\n***** PHONE BOOK APPLICATION *****\n");
		cout << ("\nMenu\n");
		cout << ("\n1. Add Contact");
		cout << ("\n2. List Contact");
		cout << ("\n3. Delete Contact");
		cout << ("\n4. Exit");
		cout << ("\n\nEnter your choice (1-4): ");
		cin >> (opt);
		fflush(stdin);
		
		switch(opt)
		{
			case 1:
				AddContact();
				break;
			case 2:
				ListContact();
				break;
			case 3:
				DeleteContact();
				break;
			case 4:
				return;
				break;
			default:
				cout << ("\nInvalid Option selected.Please select(1-4)");
				break;
		}
		
		cout << ("\nPress any key to continue...");
		getch();
	}
}

void AddContact()
{
	string line;
	
	ofstream f;
	
	f.open("Phone Book.txt",ios::out|ios::app);
	
	p.storedata();
	
	f << setw(15) << left << p.getcontactname() << setw(15) << right << p.getcontactno() << endl;
	
	cout << ("\nContact Saved...\n");
	
	f.close();
}

void ListContact()
{
	string line;
	
	ifstream f;
		
	f.open("Phone Book.txt",ios::in);
	
	cout << "ContactName     " << "    ContactNo" << endl << endl;
	while(getline(f,line))
	{
		cout << line << endl;
	}
	
	f.close();
}

void DeleteContact()
{
	string name;
	int flag = 1;
	string line;
	cout << "Enter the contact name you want to delete : ";
	cin >> name;
	
	ifstream f;
	f.open(filename,ios::in);
	
	ofstream temp;
	temp.open("temp.txt",ios::out|ios::app);

	while ( getline (f,line) )
	{
		if(name != line.substr(0,name.size()))
			temp << line << endl;
		else flag = 0;
	}
	
	if(flag == 1)
		cout << "You entered contact not found." << endl;
	else
		cout << "You entered contact deleted." << endl;
		
	f.close();
	temp.close();
	remove("Phone Book.txt");
	rename("temp.txt","Phone Book.txt");
}

