#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=500005;
struct Edge
{
	int to,w,next;
}e[MAXN<<1];
int fisrt[MAXN];
int f[MAXN];
int n,tot;
int ans;
int s;

inline void Add_Edge(int& x,int& y,int& w)
{
	e[++tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	int x,y,w;
	memset(fisrt,-1,sizeof(fisrt));
	scanf("%d%d",&n,&s);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		Add_Edge(x,y,w);	Add_Edge(y,x,w);
	}
}

void dfs(int& u,int fa)
{
	for(int i=fisrt[u];i!=-1;i=e[i].next)
		if(e[i].to!=fa)
		{
			int& v=e[i].to;	int& w=e[i].w;
			dfs(v,u);
			f[u]=max(f[u],f[v]+w);
		}
	for(int i=fisrt[u];i!=-1;i=e[i].next)
		if(e[i].to!=fa)
			ans+=f[u]-f[e[i].to]-e[i].w;
}

int main()
{
	init();
	dfs(s,-1);
	cout<<ans<<endl;
	return 0;
}
     