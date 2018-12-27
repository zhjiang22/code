#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN=105;
const int MAXM=10005;
const int INF=0x7fffff;
int g[MAXN][MAXN];
int d[MAXN][MAXN];
int pos[MAXN][MAXN];
std::vector<int> path;
int n,m;

void init()
{
	int u,v,w;
	memset(g,0x3f,sizeof(g));
	memset(pos,0,sizeof(pos));
	path.clear();
	for(int i=1;i<=n;i++)	g[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
	memcpy(d,g,sizeof(g));
}

void get_path(int u,int v)
{
	int k=pos[u][v];
	if(k==0)
		return;
	get_path(u,k);
	path.push_back(k);
	get_path(k,v);
}

void work()
{
	int ans=INF;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
			for(int j=i+1;j<k;j++)
				if((long long)d[i][j]+g[j][k]+g[k][i]<ans)
				{
					ans=d[i][j]+g[j][k]+g[k][i];
					path.clear();
					path.push_back(i);
					get_path(i,j);
					path.push_back(j);
					path.push_back(k);
				}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(d[i][j]>d[i][k]+d[k][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					pos[i][j]=pos[j][i]=k;
				}
	}
	if(ans==INF)
		printf("No solution.\n");
	else
	{
		int l=path.size();
		for(int i=0;i<l;i++)
			printf("%d%c",path[i],(i==l-1?'\n':' '));
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		init();
		work();
	}
	return 0;
}

