#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=20;
int a[MAXN][MAXN];
int v[MAXN];
int n;
int ans,sum;

void check()
{
	if(a[v[1]][v[2]]&&a[v[1]][v[3]]&&a[v[1]][v[4]])
		if(a[v[4]][v[5]])
		{
			sum++;
			ans=max(ans,a[v[1]][v[2]]+a[v[1]][v[3]]+a[v[1]][v[4]]+a[v[4]][v[5]]);
		}
}

void dfs(int cur)
{
	if(cur==5)
	{
		check();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		bool can=1;
		for(int j=1;j<=cur;j++)
			if(v[j]==i)
				can=0;
		if(can)
		{
			v[cur+1]=i;
			dfs(cur+1);
		}
	}
}

int main()
{
	freopen("question.in","r",stdin);
	freopen("question.out","w",stdout);
	int x,y,w;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		a[x][y]=w;
		a[y][x]=w;
	}
	for(int i=1;i<=n;i++)
	{
		v[1]=i;
		dfs(1);
	}
	printf("%d\n",sum/2);
	printf("%d\n",ans);
	return 0;
}
     