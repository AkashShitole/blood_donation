//exception handling doesnt execute in turbo c
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a,b,e;
	cout<<"enter values for a & b: ";
	cin>>a>>b;
	try
	{
		if(b!=0)
		{
			float div=float(a)/b;
			if(div<0)
				throw e;
			cout<<"a/b= "<<div;
		}
		else
		{
			throw b;
		}
	}
	catch(int e)
	{
		cout<<"exception: divide by zero ";
	}
	catch(char st)
	{
		cout<<"exception:division is less than 1";
	}
	catch(int w)
	{
		cout<<"unkown exception";
	}
	return 0;
}
