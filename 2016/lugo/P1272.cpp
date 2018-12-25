#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=152;
vector<int>g[MAXN];
int f[MAXN][MAXN];
int Edges[MAXN];
int n,p;
int ans=1000;

void init()
{
	int x,y;
	scanf("%d%d",&n,&p);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);	g[y].push_back(x);
		Edges[x]++;	Edges[y]++;		
	}
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<=n;i++)
		f[i][0]=0;
}

void dfs(int u,int fa)
{
	int l=g[u].size();
	for(int i=0;i<l;i++)
		if(g[u][i]!=fa)
		{
			int& v=g[u][i];
			dfs(v,u);
			for(int j=p;j>=2;j--)
				for(int k=1;k<j;k++)
					f[u][j]=min(f[u][j],f[u][k]+f[v][j-k]-2);
		}
	ans=min(ans,f[u][p]);
}

void DP()
{
	for(int i=1;i<=n;i++)
		f[i][1]=Edges[i];
	dfs(1,-1);	
	cout<<ans<<endl;
}

int main()
{
	init();
	DP();
}
     