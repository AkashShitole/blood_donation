#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream ofile;
	ofile.open("abc.txt");
	ofile<<"hi how are you?"<<endl;
	cout<<"data is written to file"<<endl;
	ofile.close();
	return 0;
}
