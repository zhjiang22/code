#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _for(i,a,b)	for(int i=(a);i<(b);i++)
#define _rep(i,a,b)	for(int i=(a);i<=(b);i++)

const int MAXN=50005;
struct Edge
{
	int to,nxt;
}e[MAXN<<1];
int first[MAXN];
int tot;
int n;

inline void Add_Edge(const int& u,const int& v)
{
	e[++tot].to=v;	
	e[tot].nxt=first[u];	first[u]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
	cin>>n;
	int u,v;
	_for(i,1,n)
	{
		scanf("%d%d",&u,&v);
		Add_Edge(u,v);	Add_Edge(v,u);
	}
}

int max_block[MAXN];
int size[MAXN];
int minv=MAXN+1;

void dfs(int u,int fa)
{
	size[u]=1;
	for(int i=first[u];i!=-1;i=e[i].nxt)
	{
		const int& v=e[i].to;
		if(v==fa)
			continue;
		dfs(v,u);
		size[u]+=size[v];
		max_block[u]=max(max_block[u],size[v]);
	}
	max_block[u]=max(max_block[u],n-size[u]);
	minv=min(minv,max_block[u]);
}

void work()
{
	dfs(1,-1);
	int i;
	for(i=1;i<=n;i++)
		if(max_block[i]==minv)
		{
			cout<<i;
			break;
		}
	for(i++;i<=n;i++)
		if(max_block[i]==minv)
			cout<<' '<<i;
	cout<<endl;
}

int main()
{
	init();
	work();
	return 0;
}