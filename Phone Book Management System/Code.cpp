#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class PhoneBook
{
	private:
		string Name, PhNo, Address;
	public:
		PhoneBook() : Name(""),PhNo(""),Address(""){}
			void setName(string name)
			{
				Name = name;
			}
			void setPhNo(string phNo)
			{
				PhNo = phNo;
			}
			void setAddress(string address)
			{
				Address = address;
			}
			string getName()
			{
				return Name;
			}
			string getPhNo()
			{
				return PhNo;
			}
			string getAddress()
			{
				return Address;
			}
};

void addNumber(PhoneBook &ph)
{
	system("cls");
	string name, phNo, address;

	cout << "\t\tEnter Name of User: ";
	cin.ignore(); // To clear any leftover newlines in the input buffer
	getline(cin, name);
	ph.setName(name);

	cout << "\t\tEnter Phone Number: ";
	getline(cin, phNo);
	ph.setPhNo(phNo);

	cout << "\t\tEnter Address of User: ";
	getline(cin, address);
	ph.setAddress(address);

	ofstream outfile("C:\\Users\\lokes\\OneDrive\\Desktop\\C++ Projects\\Phone Book Management System\\Phone Book.txt", ios::app);
	if (!outfile)
	{
		cout << "\t\tError: File Can't Open!" << endl;
	}
	else
	{
		outfile << "\t\t" << ph.getName() << " : " << ph.getPhNo() << " : " << ph.getAddress() << endl << endl;
	}
	outfile.close();
	
	cout << "\t\tPhone number Added To The Phone Book"<<endl;
	Sleep(3000);
}

void searchNumber()
{
	system("cls");
	string name;
	cout << "\t\tEnter Name of User: ";
	cin >> name;

	ifstream infile("C:\\Users\\lokes\\OneDrive\\Desktop\\C++ Projects\\Phone Book Management System\\Phone Book.txt");
	if (!infile)
	{
		cout << "\t\tError: File Can't Open!" << endl;
	}
	else
	{
		string line;
		bool found = false; // Correct initialization
		while (getline(infile, line))
		{
			stringstream ss(line);
			string userName, userPhNo, userAddress;
			getline(ss, userName, ' ');
			getline(ss, userPhNo, ' ');
			getline(ss, userAddress, ' ');

			if (name == userName)
			{
				found = true;
				cout << "\t\t\t\t" << userName << "\t" << userPhNo << "\t" << userAddress << endl;
			}
		}
		if (!found)
		{
			cout << "\t\tUser Not Found In Phone Book!" << endl;
		}
	}
	infile.close();
	Sleep(2000);
}

int main()
{
	PhoneBook ph;
	
	bool exit = false;
	while(!exit)
	{
		system("cls");
		int val;
		cout << "\t\t--------------Welcome To Phone Book Management System--------------"<<endl;
		cout << "\t\t1.Add Number"<<endl;
		cout << "\t\t2.Search Number"<<endl;
		cout << "\t\t3.Exit"<<endl;
		cout << "\t\tEnter Your Choice : ";
		cin >> val;
		
		if(val == 1){
			addNumber(ph);
		}
		else if(val == 2)
		{
			searchNumber();
		}
		else if(val == 3)
		{
			system("cls");
			exit = true;
			cout<<"\t\tGood Luck!"<<endl;
			Sleep(3000);
		}
	}
}
