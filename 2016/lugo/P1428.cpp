#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1000000;
int c[MAXN];
int maxv;
int x;
int n;

inline int lowbit(int x)
{
	return x&(-x);
}

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

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;	x++;
		add(x,1);
		cout<<sum(x-1)<<" ";
	}
	cout<<endl;
	return 0;
}
     