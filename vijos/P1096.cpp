#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a[13];
int b;
int n;

int main()
{
	for(int i=1;i<=12;i++)
		cin>>a[i];
	for(int i=1;i<=12;i++)
	{
		b+=300;
		if(b<a[i])
		{
			cout<<-i<<endl;
			return 0;
		}
		else
			b-=a[i];
		while(b>=100)
			{b-=100,n++;}
	}
	cout<<n*120+b<<endl;
	return 0;
}
     