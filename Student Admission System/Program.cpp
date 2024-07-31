#include<iostream>
#include<vector>
using namespace std;
class Student
{
	private:
		int rollno,age;
		string name;
	public:
		Student(int stdRollno,string stdName, int stdAge)
		{
			rollno = stdRollno;
			name = stdName;			
			age = stdAge;

		}
		void setRollno(int stdRollno)
		{
			rollno = stdRollno;
		}
		int getRollno()
		{
			return rollno;
		}
		void setName(string stdName)
		{
			name = stdName;
		}
		string getName()
		{
			return name;
		}
		void setAge(int stdAge)
		{
			age = stdAge;
		}
		int getAge()
		{
			return age;
		}
		void displayStudent()
		{
			cout<<"\t\tRoll Number : "<<rollno<<endl;
			cout<<"\t\tName : "<<name<<endl;
			cout<<"\t\tAge : "<<age<<endl;
		}
		
};


// Create function to add new student to the list of students
void addNewStudent(vector<Student> &students)
{
	int rollno,age;
	string name;
	cout<<"\t\tEnter Roll Number: ";
	cin>>rollno;
	// Check if student details already exist
	for(int i = 0;i<students.size();i++)
	{
		if(students[i].getRollno() == rollno)
		{
			cout<<"Student Details ALready Exists..."<<endl;
			return;
		}
	}
	cout<<"\t\tEnter Name: ";
	cin>>name;
	cout<<"\t\tEnter Age: ";
	cin>>age;
	
	Student newStudent(rollno,name,age);
	students.push_back(newStudent);
	
	cout<<"\t\tStudent details have been added successfully."<<endl;
}

// Function to display all the details of the students
void displayAllStudentDetails(vector<Student> &students)
{
	
	//To check whether the list of students is empty or not.
	if(students.empty())
	{
		cout<<"\t\tNo Students Found"<<endl;
		return;
	}
	for(int i = 0;i < students.size();i++)
	{
		students[i].displayStudent();
		cout<<endl;
	}
}

// Function to search the Student details
void searchStudent(vector<Student> &students)
{
	int rollno;
	bool found = false;
	cout<<"\t\tEnter the Roll Number: ";
	cin>>rollno;
	for(int i = 0; i<students.size();i++)
	{
		if(students[i].getRollno() == rollno)
		{
			found = true;
			cout<<"\t\t-------------STUDENT FOUND-------------"<<endl;
			students[i].displayStudent();
			cout<<endl;
			return;
		}
	}
	if(found==false)
		{
			cout<<"\t\t------------STUDENT NOT FOUND------------"<<endl;
			return;
		}		
}

// Function to Updata the details of the Student
void updateStudentDetails(vector<Student> &students)
{
	string sname;
	bool found =  false;
	int choice;
	
	cout<<"\t\tEnter Name of the Student to Update the Record :";
	cin.ignore();
	getline(cin,sname);
	
	for(int i = 0;i < students.size();i++)
	{
		if(students[i].getName() == sname)
		{
			found = true;
			
			cout<<"\t\t------------STUDENT FOUND-----------"<<endl;
			cout<<"\t\t1.Update Rollno "<<endl;
			cout<<"\t\t2.Update Name "<<endl;
			cout<<"\t\t3.Update Age "<<endl;
			cout<<"Enter Your Choice : ";
			cin>>choice;
			
			switch(choice)
			{
				case 1:{

					int rno;
					cout<<"\t\tEnter New Roll Number : ";
					cin>>rno;
					students[i].setRollno(rno);
					break;
				}
					
				case 2:{

					string name;
					cout<<"\t\tEnter New Name : ";
					cin.ignore();
					getline(cin,name);
					students[i].setName(name);
					break;
				}
					
				case 3 :{

					int age;
					cout<<"\t\tEnter New Age : ";
					cin>>age;
					students[i].setAge(age);
					break;
				}
					
				default : 
					cout<<"\t\tInvalid Number..."<<endl;
					
			}
		}
	
	}
		if(!found)
		{
			cout<<"\t\tRecord Not Found..."<<endl;
			return;
		}
}


//Function to delete the Student in the list
void deleteStudent(vector<Student> &students)
{
	string name;
	cout<<"\t\tEnter Name Of The Student To Delete : ";
	cin.ignore();
	getline(cin,name);
	
	for(int i = 0;i<students.size();i++)
	{
		if(students[i].getName()==name)
		{
			students.erase((students.begin()+i));
			cout<<"\t\tStudent details Removed Succssfully..."<<endl;
		}
	}
}
int main()
{
	vector<Student> students;
	students.push_back(Student(1,"Lokesh",20));
	
	char choice;
	do
	{
		system("cls");
		int op;
		cout<<"\t\t---------------------------------------"<<endl;
		cout<<"\t\t\tSTUDENT MANAGEMENT SYSTEM"<<endl;
		cout<<"\t\t---------------------------------------"<<endl<<endl;
		cout<<"\t\t1. Add New Student"<<endl;
		cout<<"\t\t2. Display All students"<<endl;
		cout<<"\t\t3. Search Student"<<endl;
		cout<<"\t\t4. Update Student"<<endl;
		cout<<"\t\t5. Delete Student"<<endl;
		cout<<"\t\t6. Exit"<<endl;
		cout<<"\t\tEnter your choice: ";
		cin>>op;
		switch(op)
		{
			case 1 : 
				addNewStudent(students);
				break;
			
			case 2 :
				displayAllStudentDetails(students);
				break;
				
			case 3 :
				searchStudent(students);
				break;
				
			case 4 :
				updateStudentDetails(students);
				break;
				
			case 5 :
				deleteStudent(students);
				break;
				
			case 6 :
				exit(1);
			default :
				cout<<"\t\tEnter Valid Number...."<<endl;
		}
		cout<<"\t\tDo You Want To Continue [Yes/No] ? :";
		cin>>choice;
	}while(choice == 'y' || choice == 'Y');
	
    
    return 0;
}
