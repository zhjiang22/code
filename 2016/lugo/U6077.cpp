#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=505;
const int MAXM=3005;
struct Edge
{
	int to,w,next;
}e[MAXM<<1];
int fisrt[MAXN];
int cnt[MAXN],in[MAXN];
int d[MAXN];
int n,m,p;
int T,tot;
queue<int> q;

inline void Add_Edge(int& x,int& y,int w)
{
	e[++tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));	tot=0;
	scanf("%d%d%d",&n,&m,&p);
	int x,y,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		Add_Edge(x,y,w);	Add_Edge(y,x,w);
	}
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		Add_Edge(x,y,-w);
	}
}

bool SPFA(int& s)
{
	memset(cnt,0,sizeof(cnt));	memset(in,0,sizeof(in));
	memset(d,0x3f,sizeof(d));
	while(!q.empty())	q.pop();
	q.push(s);	in[s]=1;	cnt[s]=1;	d[s]=0;
	while(!q.empty())
	{
		if(d[s]<0)
			return 1;
		int u=q.front();	q.pop();	in[u]=0;
		for(int i=fisrt[u];i!=-1;i=e[i].next)
		{
			int& to=e[i].to;	int& w=e[i].w;
			if(d[to]>d[u]+w)
			{
				d[to]=d[u]+w;
				if(!in[to])
				{
					q.push(to);
					in[to]=1;	cnt[to]++;
					if(cnt[to]>n)
						return 1;
				}
			}
		}
	}
	return 0;
}

void work()
{
	for(int i=1;i<=n;i++)
		if(SPFA(i))
		{
			printf("YES\n");	
			return;
		}
	printf("NO\n");
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		init();
		work();
	}
}
     