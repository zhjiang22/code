#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

const int MAXN=15;
int a[MAXN];
bool v[MAXN];
int n;

void print()
{
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void dfs(int cur)
{
	if(cur==n+1)
	{
		print();
		return;
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
		{
			v[i]=1;	a[cur]=i;
			dfs(cur+1);
			v[i]=0;
		}
}

int main()
{
	scanf("%d",&n);
	dfs(1);
}