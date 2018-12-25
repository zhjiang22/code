#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define lowbit(x) (x)&(-x);
const int MAXN=300005;
const int MAXV=1000005;
struct car
{
	int p,v;
	bool operator <(const car& b)const
	{
		return p<b.p;
	}
}a[MAXN];
int c[MAXV];
long long ans;
int n;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].p,&a[i].v);
	sort(a+1,a+n+1);
}

void update(int x,int d)
{
	while(x<=MAXV)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

long long sum(int x)
{
	long long tot=0;
	while(x>0)
	{
		tot+=c[x];
		x-=lowbit(x);
	}
	return tot;
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		ans+=i-sum(a[i].v)-1;
		update(a[i].v,1);
	}
	printf("%lld\n",ans);
}

int main()
{
	init();
	work();
}
     