#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=15;
bool v[MAXN];
int a[MAXN];
int g[MAXN];
int n,sum;

void init()
{
	scanf("%d%d",&n,&sum);
	g[0]=1;	n--;
	for(int i=1;i<=n;i++)
		g[i]=g[i-1]*(n-i+1)/i;
	n++;
}

void print()
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void dfs(int cur,int s)
{
	if(s>sum)
		return;
	if(cur>=n)
	{
		if(s==sum)
		{
			print();
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
		{
			v[i]=1;	a[cur]=i;
			dfs(cur+1,s+i*g[cur]);
			v[i]=0;
		}
}

int main()
{
	init();
	dfs(0,0);
}
     