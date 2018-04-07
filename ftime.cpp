#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

#define FILE_NAME "time.dat"

void writetime(int h,int m,int s)
{
	char str[10];
	file.open("abc.txt",ios::out|ios::binary);
	
	if(!file)
	{
		cout<<"error in creating file!!!"<<endl;
		return;
	}
	sprintf(str,"%02d:%02d:%2d",h,m,s);
	cout<<"time"<<str<<"has been written in to file"<<endl;
	
	file.close();
}

void readtime(int *h,int *m,int *s)
{
	char str[20];
	int inH,inM,inS;
	
	fstream finc;
	finc.open(FILE_NAME,ios::in|ios::binary);
	if(!finc)
	{
		cout<<"error in file opening"<<endl;
		return;
	}
	if(finc,read((char*)))
	
}
