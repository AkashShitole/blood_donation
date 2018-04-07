#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int id,phone,dob;
	char name[20];
	ofstream ofile;
	ofile.open("employee.txt");
	ofile.close();
	
	//ifstream.ifile;
	ifile.open("employee.txt");
	
	cout<<"enter name";
	cin>>name;
	
	cout<<"enter id";
	cin>>id;
	
	cout<<"enter phone no.";
	cin>>phone;
	
	cout<<"enter date of birth";
	cin>>dob;
	
	ifile.close();
	
	return 0;
}
