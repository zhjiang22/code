#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
int a[MAXN],b[MAXN],c[MAXN];
int p[MAXN];
long long t[MAXN];
long long ans;
int n,m;

inline int lowbit(int x){return x&(-x);}

void add(int x,int d)
{
	while(x<=n)
	{
		t[x]+=d;
		x+=lowbit(x);
	}
}

long long sum(int x)
{
	long long ans=0;
	while(x>0)
	{
		ans+=t[x];
		x-=lowbit(x);
	}
	return ans;
}

void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
}

int main()
{
	init();
	int cur=p[1];
	for(int i=2;i<=m;i++)
	{
		int q=min(cur,p[i]);	int w=max(cur,p[i]);
		add(q,1);	add(w,-1);
		cur=p[i];
	}
	for(int i=1;i<n;i++)
		ans+=min(sum(i)*a[i],c[i]+sum(i)*b[i]);
	cout<<ans<<endl;
	return 0;
}
     