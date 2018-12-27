#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

char w[100002];
int a,b;
int c,d;
char ch;

int main()
{
	int n=0;
	while(ch=getchar())
	{
		if(ch=='E')
			break;
		if(ch=='W')
			a++;
		else if(ch=='L')
			b++;
		w[n++]=ch;
		if((a>=11||b>=11)&&(a-b>=2||b-a>=2))
		{
			cout<<a<<":"<<b<<endl;
			a=b=0;
		}
	}
	cout<<a<<":"<<b<<endl;
	a=b=0;
	cout<<endl;
	for(int j=0;j<n;j++)
	{
		if(w[j]=='W')
			a++;
		else if(w[j]=='L')
			b++;
		if((a>=21||b>=21)&&(a-b>=2||b-a>=2))
		{
			cout<<a<<":"<<b<<endl;
			a=b=0;
		}
	}
	cout<<a<<":"<<b<<endl;
	return 0;
}
     