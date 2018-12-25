#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int a[MAXN];
int f1[MAXN];
int f2[MAXN];
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}

void getf1()
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if(a[i]>a[j])
				f1[i]=max(f1[i],f1[j]+1);
}

void getf2()
{
	for(int i=n;i>=1;i--)
		for(int j=n+1;j>i;j--)
			if(a[i]>a[j])
				f2[i]=max(f2[i],f2[j]+1);
}

void out()
{
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,f1[i]+f2[i]-1);
	cout<<ans<<endl;
}

int main()
{
	init();
	getf1();
	getf2();
	out();
	return 0;
}
     