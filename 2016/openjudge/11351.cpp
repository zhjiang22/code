#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=30;
int a[MAXN];
int b[MAXN];

void init()
{
	string x,y;
	cin>>x>>y;
	int lx=x.length();
	int ly=y.length();
	for(int i=0;i<lx;i++)
		a[x[i]-'A']++;
	for(int i=0;i<ly;i++)
		b[y[i]-'A']++;
}

int main()
{
	init();
	for(int i=0;i<26;i++)
		if(a[i]!=0)
		{
			bool can=0;
			for(int j=0;j<26;j++)
				if(b[j]!=0&&a[i]==b[j])
				{
					b[j]=0;
					can=1;
					break;
				}
		if(!can)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
     