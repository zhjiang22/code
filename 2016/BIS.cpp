#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=500;
int c[MAXN];
int n;

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int d)
{
	while(x<=n)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

int getsum(int x)
{
	int sum=0;
	while(x>0)
	{
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

int main()
{
	cin>>n;
	int d;
	for(int i=1;i<=n;i++)
	{
		cin>>d;
		add(i,d);
	}
	int x,y;
	while(1)
	{
		cin>>d;
		if(d==1)
		{
			cin>>x>>y;
			add(x,y);
		}
		else	if(d==2)
		{
			cin>>x>>y;
			cout<<getsum(y)-getsum(x-1)<<endl;
		}
		else	
			break;
	}
	return 0;

}
     