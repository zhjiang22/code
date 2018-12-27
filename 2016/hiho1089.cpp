#include<bits/stdc++.h>
using namespace std;

const int MAXN=105;
int g[MAXN][MAXN];
int n,m;

void init()
{
	memset(g,0x3f,sizeof(g));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	int x,y,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		g[x][y]=g[y][x]=min(g[x][y],w);
	}
}

void work()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%d%c",g[i][j],j==n?'\n':' ');
}

int main()
{
	init();
	work();
	return 0;
}
     