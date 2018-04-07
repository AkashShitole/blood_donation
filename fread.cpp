#include<iostream>
#include<fstream>

using namespace std;

int main()
{
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
