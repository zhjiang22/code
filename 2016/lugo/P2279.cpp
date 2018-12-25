#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=1005;
struct Edge
{
	int to,next;
}e[MAXN<<1];
vector<int> g[MAXN];
int fisrt[MAXN];
int fa[MAXN];
int d[MAXN];
bool doin[MAXN];
int n,tot;
int D;
int ans;

inline void Add_Edge(int& x,int& y)
{
	e[++tot].to=y;	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	int x;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		Add_Edge(i,x);	Add_Edge(x,i);
	}
}

void dfs(int u,int father)
{
	fa[u]=father;
	g[d[u]].push_back(u);
	for(int i=fisrt[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(v!=father)
		{
			d[v]=d[u]+1;	D=max(D,d[v]);
			dfs(v,u);
		}
	}
}

void cover(int u,int fa,int cur)
{
	doin[u]=1;
	if(cur>1)
		return;
	for(int i=fisrt[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(v!=fa)
			cover(v,u,cur+1);
	}
}

int main()
{
	init();
	dfs(1,-1);
	for(int k=D;k>=0;k--)
	{
		int l=g[k].size();
		for(int i=0;i<l;i++)
		{
			int& u=g[k][i];
			if(doin[u])
				continue;
			ans++;
			if(fa[u]<0)
				cover(fa[fa[u]],-1,0);
			else
				cover(fa[fa[u]],-1,0);
		}
	}
	cout<<ans<<endl;
	return 0;
}
     