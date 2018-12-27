#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

string a;
string b;
int l1,l2;
int f;
int k[105];

int main()
{
	cin>>a>>b;
	l1=a.length();
	l2=b.length();
	while(1)
	{
		int now=0;
		int cur=0;
		while(1)
		{
			int x=a.find(b[cur]);
			cur=(cur+1)%(l2);
			if(x==-1)
			{
				f=1;
				break;
			}
			else
				k[++now]=x;
			if(now==l2)
				break;
		}
		if(f==1)
			break;
		else
			for(int i=1;i<=now;i++)
				a[k[i]]=0;
	}
	for(int i=0;i<l1;i++)
		if(a[i]!=0)
			cout<<a[i];
	return 0;
}
     