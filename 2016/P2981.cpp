#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define lowbit(x)	(x&(-x))

const int MAXN=1000005;
int c[MAXN];
int a[MAXN];
int n,m,k;

void add(int x,int d)
{
	while(x<=MAXN)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

void init()
{
	string x;
	cin>>n;
	int p;
	for(int i=1;i<=n;i++)
	{
		cin>>p>>x;
		a[p]=1;	add(p,1);
	}
}

int main()
{
	init();
	int x,y,z;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if(z>0)
		{
			for(int i=y+z;i>=x+z;i--)
			{
				add(i,a[i-z]-a[i]);
				a[i]=a[i-z];
			}
			for(int i=x;i<x+z;i++)
			{
				add(i,-a[i]);
				a[i]=0;
			}
		}
		else
		{
			for(int i=x+z;i<=y+z;i++)
			{
				add(i,a[i-z]-a[i]);
				a[i]=a[i-z];
			}
			for(int i=y+z;i<y;i++)
			{
				add(i,0-a[i]);
				a[i]=0;
			}
		}
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		cout<<sum(y)-sum(x-1)<<endl;
	}
	return 0;
}
     