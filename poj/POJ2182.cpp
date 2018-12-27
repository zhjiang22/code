#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=8005;
int a[MAXN];
int c[MAXN];
int H[MAXN];
int n;

void add(int p,int x)
{
	for(;p<=n;p+=p&-p)
		c[p]+=x;
}

int ask(int p)
{
	int sum=0;
	for(;p;p-=p&-p)
		sum+=c[p];
	return sum;
}

void init()
{
	cin>>n;
	for(int i=2;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		add(i,1);
}

void work()
{
	for(int i=n;i>=1;i--)
	{
		int x=a[i]+1;
		int sum=0,ans=0;
		int cnt=0;
		while((1<<cnt)<=x)
			cnt++;
		cnt--;
		for(int k=cnt;k>=1;k--)
			if(ans+(1<<k)<=n&&sum+c[ans+(1<<k)]<x)
			{
				ans+=(1<<k);
				sum+=c[ans+(1<<k)];
			}
		H[i]=ans+1;
		add(ans+1,-1);
	}
	for(int i=1;i<=n;i++)
		cout<<H[i]<<endl;
}

int main()
{
	init();
	work();
	return 0;
}
     
/*#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=8005;
int a[MAXN];
int c[MAXN];
int H[MAXN];
int n;

void add(int p,int x)
{
	for(;p<=n;p+=p&-p)
		c[p]+=x;
}

int ask(int p)
{
	int sum=0;
	for(;p;p-=p&-p)
		sum+=c[p];
	return sum;
}

void init()
{
	cin>>n;
	for(int i=2;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		add(i,1);
}

void work()
{
	for(int i=n;i>=1;i--)
	{
		int x=a[i]+1;
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(ask(mid)>=x)
				r=mid;
			else
				l=mid+1;
		}
		H[i]=l;
		add(l,-1);
	}
	for(int i=1;i<=n;i++)
		cout<<H[i]<<endl;
}

int main()
{
	init();
	work();
	return 0;
}*/
     