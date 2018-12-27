#include <iostream>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <queue>
using namespace std;

const int MAXN=30099;
struct Edge
{
	int to,nxt;
}e[MAXN];
int first[MAXN];
int inv[MAXN];
int n,m;
int tot;
int maxd;

inline void Add_Edge(const int& u,const int& v)
{
	e[++tot].to=v;
	e[tot].nxt=first[u];	first[u]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
 	scanf("%d%d",&n,&m);
 	maxd=max(n,m)/30+5;
 	int u,v;
 	for(int i=1;i<=m;i++)
 	{
 		scanf("%d%d",&u,&v);
 		Add_Edge(v,u);
 		inv[u]++;
 	}
}

bitset<MAXN> f[MAXN];

void work()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
		f[i].set(i);
	for(int i=1;i<=n;i++)
		if(!inv[i])
			q.push(i);
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		for(int i=first[u];i!=-1;i=e[i].nxt)
		{
			const int& v=e[i].to;
			inv[v]--;
			if(!inv[v])
				q.push(v);
			f[v]|=f[u];
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",(int)f[i].count());
}

int main()
{
	init();
	work();
	return 0;
}