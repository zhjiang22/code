#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=8000;
int g[MAXN][MAXN];
int n,m;

void init()
{
	int x,y,w;
	scanf("%d%d",&n,&m);
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		g[x][y]=g[y][x]=w;
	}
}	

void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

void out()
{
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",g[x][y]);
	}
}

int main()
{
	init();
	Floyd();
	out();
	return 0;
}
     