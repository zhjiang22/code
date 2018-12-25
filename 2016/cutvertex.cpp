#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
const int MAXM=3005;
const int INF=(1<<30)-1;
struct Edge
{
	int to,next;
}e[MAXM<<1];
int fisrt[MAXN];
int pre[MAXN],low[MAXN];
bool incut[MAXN];
int cnt_clock;
int n,m,tot;

inline void Add_Edge(int x,int y)
{
	tot++;	e[tot].to=y;	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	int x,y;
	memset(fisrt,-1,sizeof(fisrt));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		Add_Edge(x,y);	Add_Edge(y,x);
	}
}

int dfs(int u,int fa)
{
	int lowu=pre[u]=++cnt_clock;
	int child=0;
	for(int i=fisrt[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(!pre[v])//子节点
		{
			child++;
			int lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>=pre[u])
				incut[u]=true;
		}
		else	if(pre[v]<=pre[u]&&v!=fa)
			lowu=min(lowu,pre[v]);
	}
	if(fa<0&&child==1)
		incut[u]=0;
	return low[u]=lowu;
}

void cutvertex()
{
	for(int i=1;i<=n;i++)
		if(!pre[i])
			dfs(i,-1);
	for(int i=1;i<=n;i++)
		if(incut[i])
			cout<<i<<endl;
}

int main()
{
	init();
	cutvertex();
	return 0;
}
     