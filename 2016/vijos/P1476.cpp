#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=400005;
struct Edge
{
	int to,next;
}e[MAXN<<2];
int fisrt[MAXN];//Edges
int fa[MAXN];
int d[MAXN];
bool vis[MAXN];
int n,tot;
int l,p;

int main()
{

}
     

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

const int MAXN=400005;
struct Edge
{
	int to,next;
}e[MAXN<<2];
int fisrt[MAXN];//Edges
int fa[MAXN];
int d[MAXN];
bool vis[MAXN];
int n,tot;
int l,p;
set<int> ans;

inline void Add_Edge(int x,int y)
{
	e[++tot].to=y;	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	int x,y;
	memset(fisrt,-1,sizeof(fisrt));
	cin>>n;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		Add_Edge(x,y);	Add_Edge(y,x);
	}
}

void dfs(int u)
{
	vis[u]=1;
	if(d[u]>l)
	{
		l=d[u];
		p=u;
	}
	for(int i=fisrt[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(!vis[v])
		{
			d[v]=d[u]+1;
			dfs(v);
		}
	}
}

void dfs1(int u,int father)
{
	if(father!=-1)
		d[u]=d[father]+1;
	fa[u]=father;
	for(int i=fisrt[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(v!=father)
			dfs1(v,u);
	}
}

int main()
{
	init();
	memset(d,0,sizeof(d));	memset(vis,0,sizeof(vis));
	dfs(0);
	memset(d,0,sizeof(d));	memset(vis,0,sizeof(vis));
	dfs(p);
	memset(d,0,sizeof(d));
	dfs1(p,-1);
	for(int i=0;i<n;i++)
	{
		if(d[i]>=l)
		{
			int u=i;
			while(u!=p)
			{
				if(!ans.count(u))
					ans.insert(u);
				u=fa[u];
			}
			cout<<endl;
		}
	}
	if(!ans.count(p))
		ans.insert(p);
	set<int>::iterator it;
	for(it=ans.begin();it!=ans.end();it++) 
    	cout<<*it<<endl;
    return 0;
}
*/