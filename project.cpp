#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class record
{
	public: 
		char name[20], gender, bloodgrp[5];
		char dob[11], date[11];
		int id; 
	
	void disp();
	public:
		void get();
		void wtf();
		void rff();
		void search();
		void del();
		void mod();
}c;

void record::get()
{
	cout<<"\n Enter id: ";
	cin>>id;
	cout<<"\n Enter name of donor: ";
	cin>>name;
	cout<<"\n Enter gender(M/F): ";
	cin>>gender;
	cout<<"\n Enter date of birth(dd-mm-yyyy): ";
	cin>>dob;
	cout<<"\n Enter date of donation(dd-mm-yyyy): ";
	cin>>date;
	cout<<"\n Enter blood group of donor: ";
	cin>>bloodgrp;
}
void record::disp()
{
	cout<<"\t\t Record Of Donor"<<endl;
	cout<<"ID: "<<id<<endl;
	cout<<"Name of donor: "<<name<<endl;
	cout<<"Gender: "<<gender<<endl;
	cout<<"Blood Group: "<<bloodgrp<<endl;
	cout<<"Date of Birth: "<<dob<<endl;
	cout<<"Date of Donation: "<<date<<endl;
}
void record::wtf()
{
	ofstream ofile;
	ofile.open("record.txt",ios::app);
	get();
	ofile.write((char*)&c, sizeof(c));
	ofile.close();	
}
void record::rff()
{
	ifstream ifile;
	ifile.open("record.txt");
	ifile.seekg(0,ios::beg);
	ifile.read((char*)&c, sizeof(c));
	while(ifile)
	{
		disp();	
		ifile.read((char*)&c, sizeof(c));
	}
	ifile.close();
}
void record::search()
{
	char s[20];
	ifstream ifile("record.txt");
	cout<<"Enter name of donor to be searched: "<<endl;
	cin>>s;
	ifile.seekg(0, ios::beg);
	ifile.read((char*)&c, sizeof(c));
	while(ifile)
	{
		if(strcmpi(s,name)==0)
		disp();
		ifile.read((char*)&c, sizeof(c));
	} 
}
void record::del()
{
	char b[20];
    ifstream ifile;
    ifile.open("record.txt", ios::app);
    ofstream ofile;
    ofile.open("new.txt", ios::app);
    puts("\nEnter name of the record whose record you want to delete: ");
    cin>>b;
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
        if (strcmpi(b, name))
            ofile.write((char*)&c, sizeof(c));
        ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
    ofile.close();
    remove("record.txt");
    rename("new.txt", "record.txt");
}
void record::mod()
{
	char m[20];
	int ch;
	cout<<"\nEnter name of donor you want to modify: "<<endl;
	gets(m);
	fstream f;
	f.open("record.txt",ios::in|ios::out);
	f.seekg(0, ios::beg);
	f.read((char*)&c, sizeof(c));
	int a=f.tellg();
	while(!f.eof())
	{
		if(!strcmpi(m,name))
		{
			puts("\n1. Change name\n2. Change gender\n3. Change Date of Birth\n4. Change blood group\n5. Change date of donation\n Enter your Choice: ");
			cin>>ch;
			switch(ch)
			{
				case 1:
					gets(name);
					break;
				case 2:
					cin>>gender;
					break;
				case 3:
					cin>>dob;
					break;
				case 4:
					cin>>bloodgrp;
					break;
				case 5:
					cin>>date;
					break;
				default:
					cout<<"\ninvalid input"<<endl;
					break;
			}
			f.seekg(a-sizeof(c),ios::beg);
			f.write((char*)&c, sizeof(c));
		}
		f.read((char*)&c, sizeof(c));
		a=f.tellg();
	}
	f.close();
}
int main()
{
	int choice;
	char n;
	mainmenu:
	do
	{
		cout<<"\t\t BLOOD DONATION";
		cout<<"\n************************************* ";
		cout<<"\n\n 1.View donor details";
		cout<<"\n\n 2.Add new donor";
		cout<<"\n\n 3.Search for a donor from record";
		cout<<"\n\n 4.Delete a donor record";
		cout<<"\n\n 5.Modify a donor record";
		cout<<"\n************************************* ";
		cout<<"\nEnter your choice"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				c.rff();
				break;
			case 2:
				c.wtf();
				break;
			case 3:
				c.search();
				break;
			case 4:
				c.del();
				break;
			case 5:
				c.mod();
				break;
			default:
				cout<<"\nerror!!!"<<endl;
				break;
		}
		cout<<"\ncontinue?(y/n)"<<endl;
		cin>>n;
	}
	while(n=='y');

	cout<<"\n Good Bye"<<endl;

	return 0;
}
