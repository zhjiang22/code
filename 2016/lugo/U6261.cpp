#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
#define LL long long
using namespace std;

const int MAXN=10005;
const int MAXLOG=80;
struct Edge
{
	int to,next;
}e[MAXN<<1];
int first[MAXN];
int f[MAXN][MAXLOG];
int a[MAXN];
LL q[MAXN];
int n,tot;
LL MAX;
LL m;

void init()
{
	memset(f,-1,sizeof(f));
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&f[i][0]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%lld",&a[i],&q[i]);
		MAX=max(MAX,q[i]);
	}
}

void work()
{
	for(int j=1;((LL)1<<j)<=MAX;j++)
		for(int i=1;i<=n;i++)
		{
			int& a=f[i][j-1];
			f[i][j]=f[a][j-1];
		}
}

void work(int i)
{
	int s=a[i];	LL t=q[i];
	LL maxlog=0;
	while(((LL)1<<maxlog)<=t)	
		maxlog++;	
	maxlog--;
	for(int i=maxlog;i>=0;i--)
		if((t-((LL)1<<i))>=0)
		{
			t-=(LL)1<<i;
			s=f[s][i];
		}
	printf("%d\n",s);
}

void question()
{
	for(int i=1;i<=m;i++)
		work(i);
}

int main()
{
	init();
	work();
	question();
}