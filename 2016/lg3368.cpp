#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXN=500005;
int c[MAXN];
int a[MAXN];
int n,m;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}

void add(int p,int x)
{
	for(;p<=n;p+=p&-p)
		c[p]+=x;
}

LL ask(int p)
{
	LL sum=0;
	for(;p;p-=p&-p)
		sum+=c[p];
	return sum;
}

void work()
{
	int k,l,r,x;
	while(m--)
	{
		cin>>k;
		if(k==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			add(l,x);
			add(r+1,-x);
		}
		else
		{
			scanf("%d",&x);
			printf("%lld\n",a[x]+ask(x));
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}
     