#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream st; //creating object of fstream
	st.open("studytonight.txt",ios::out);
	if(!st)//checking if file exists
	{
		cout<<"file creation failed";
	}
	else
	{
		cout<<"new file created";
		st.close();
	}
	return 0;
}
