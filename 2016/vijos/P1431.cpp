#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int m,s,t;
int a,b;
int i;

int main()
{
	cin>>m>>s>>t;
	for(i=1;i<=t;i++)
	{
		a+=17;
		if(m>=10)
		{
			m-=10;
			b+=60;
		}
		else
			m+=4;
		if(a<b)	a=b;
		if(a>s)
		{
			cout<<"Yes"<<endl<<i;
			return 0;
		}
	}
	if(a>s)
		cout<<"Yes"<<endl<<i;
	else
		cout<<"No"<<endl<<a;
	return 0;
}
     