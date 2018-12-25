#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=205;
const int MAXM=40005;
struct Edge
{
	int to,next,w;
	Edge()
	{
		to=next=-1;
		w=0;
	}
}e[MAXN<<1];
int first[MAXN];
int v[MAXN][MAXN];
int n,m,t,tot;
int l=1,r;
int te,maxw;

inline void Add_Edge(int x,int y,int w)
{
	tot++;
	e[tot].to=y;	e[tot].w=w;
	e[tot].next=first[x];	first[x]=tot;
}

void init()
{
	int x,y,w;
	cin>>n>>m>>t;
	memset(first,-1,sizeof(first));
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		Add_Edge(x,y,w);
		Add_Edge(y,x,w);
		r=max(r,w);
	}
}

void dfs(int now)
{
	if(now==n)
	{
		te++;
		return;
	}
	for(int i=first[now];i!=-1;i=e[i].next)
	{
		int w=e[i].w;	if(w>maxw)	continue;
		int u=e[i].to;	
		if(!v[now][u])
		{
			v[now][u]=v[u][now]=1;
			dfs(u);
			v[now][u]=v[u][now]=0;
		}
	}
}

bool check(int x)
{
	memset(v,0,sizeof(v));
	te=0;	maxw=x;
	dfs(1);
	if(te>=t)
		return 1;
	else
		return 0;
}


int main()
{
	init();
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}
     