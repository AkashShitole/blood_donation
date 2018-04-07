#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream ofile;
	ofile.open("txt.txt");
	ofile<<"hi how are you?"<<endl;
	cout<<"data is written to file"<<endl;
	ofile.close();
	
	char data[100];
	
	ifstream ifile;
	ifile.open("abc.txt");
	
	while(!ifile.eof())
	{
		ifile.getline(data,100);
		cout<<data<<endl;
	}
	ifile.close();
	return 0;
}
