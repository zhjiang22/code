#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

const int MAXN=3005;
const int MAXM=8005;
const int INF=(1<<28)-1;
struct Edge
{
	int to,next;
}e[MAXM];
int first[MAXN];//Edges
int w[MAXN];//Waste
int n,m,p,tot;//Map
stack<int> s;queue<int> q;
int scc_cnt,Clock_cnt;
int low[MAXN],pre[MAXN];
int sccno[MAXN];//SCC
int in[MAXN],minw[MAXN];
int ans;//Work

inline void Add_Edge(int& x,int& y)
{
	e[++tot].to=y;
	e[tot].next=first[x];	first[x]=tot;
}

void init()
{
	int x,y;
	memset(first,-1,sizeof(first));
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
		w[i]=INF;
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d",&x,&y);
		w[x]=y;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Add_Edge(x,y);
	}
}

void check()
{
	bool vis[MAXN];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(w[i]!=INF)
			q.push(i),vis[i]=1;
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		for(int i=first[u];i!=-1;i=e[i].next)
		{
			int& v=e[i].to;
			if(!vis[v])
			{
				vis[v]=1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			cout<<"NO"<<endl;
			cout<<i<<endl;
			exit(0);
		}
}

void dfs(int u)
{
	pre[u]=low[u]=++Clock_cnt;
	s.push(u);
	for(int i=first[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(!pre[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else	if(!sccno[v])
			low[u]=min(low[u],pre[v]);
	}
	if(low[u]==pre[u])
	{
		int x;
		scc_cnt++;	minw[scc_cnt]=INF;
		do
		{
			x=s.top();	s.pop();	
			minw[scc_cnt]=min(minw[scc_cnt],w[x]);
			sccno[x]=scc_cnt;
		}
		while(x!=u);
	}
}

void Tarjan()
{
	for(int i=1;i<=n;i++)
		if(!pre[i])
			dfs(i);
}

void Work()
{
	memset(in,0,sizeof(in));
	for(int u=1;u<=n;u++)
		for(int i=first[u];i!=-1;i=e[i].next)
		{
			int& v=e[i].to;
			if(sccno[u]!=sccno[v])
				in[sccno[v]]=1;
		}
	for(int i=1;i<=scc_cnt;i++)
		if(!in[i])
			ans+=minw[i];
	cout<<"YES"<<endl;
	cout<<ans<<endl;
}

int main()
{
	init();
	check();
	Tarjan();
	Work();
}
     