#include<iostream>
using namespace std;

int main()
{
	int a[6];
	int i,e;
	cout<<"\nEnter elements: ";
	for(i=0;i<5;i++)
	{
		cin>>a[i];
	}
	try
	{
		if(a[6]='\0')
		{
			cout<<"values are: ";
	
			for(i=0;i<5;i++)
			{
				cout<<"\t"<<a[i];
			}
		}
		else
		{
			throw e;
		}
	}
	catch(int e)
	{
		cout<<"Array Out of Bound";
	}
	return 0;
}
