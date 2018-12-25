#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXV=400005;
const int MAXN=100005;
const int INF=0x7fffff;
struct node
{
	int to,next;
	node()
	{
		to=next=-1;
	}
}e[MAXV];
int fisrt[MAXN];
int c[MAXN];
int d[MAXN];
int can[MAXN];
int w[MAXN];
int Q[MAXN];
int in[MAXN];
int no[MAXN];
int n,m;
int k,s;
int p,q;
int ans;
int tot;
int rear,front;

void inline Add_Edge(int x,int y)
{
	tot++;
	e[tot].to=y;
	e[tot].next=fisrt[x];
	fisrt[x]=tot;
}

void init()
{
	int x,y;
	memset(fisrt,-1,sizeof(fisrt));
	scanf("%d%d%d%d",&n,&m,&k,&s);
	scanf("%d%d",&p,&q);
	for(int i=1;i<=k;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Add_Edge(x,y);
		Add_Edge(y,x);
	}
}

void dfs(int x,int cur)
{
	if(cur==s+1)
		return;
	if(can[x])
		return;
	can[x]=1;
	for(int i=fisrt[x];i!=-1;i=e[i].next)
		dfs(e[i].to,cur+1);
}

void inline getw()
{
	for(int i=2;i<n;i++)
		if(can[i])
			w[i]=q;
		else
			w[i]=p;
	for(int i=1;i<=k;i++)
		no[c[i]]=1;
}

void SPFA(int s)
{
	for(int i=1;i<=n;i++)
		d[i]=INF;
	d[s]=0;
	Q[rear++]=s;
	in[s]=1;
	while(rear!=front)
	{
		int x=Q[front];
		front=(front+1)%(MAXN-2);
		in[x]=0;
		for(int i=fisrt[x];i!=-1;i=e[i].next)
		{
			int u=e[i].to;
			if(no[u])
				continue;
			if(d[u]>d[x]+w[u])
			{
				d[u]=d[x]+w[u];
				if(!in[u])
				{
					in[u]=1;
					Q[rear]=u;
					rear=(rear+1)%(MAXN-2);
				}
			}
		}
	}
	printf("%d\n",d[n]);
}

int main()
{
	init();
	for(int i=1;i<=k;i++)
		dfs(c[i],0);
	getw();
	SPFA(1);
	return 0;
}
     