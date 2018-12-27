#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN=1005;
const int MAXM=20005;
struct Edge
{
	int to,nxt,w;
}e[MAXM];
struct Point
{
	int x,d;
	bool operator<(const Point& p)const
	{
		return d>p.d;
	}
};
int first[MAXN];
int n,m,k;
int tot;
int maxL;

inline void Add_Edge(const int& u,const int& v,const int& w)
{
	e[++tot].to=v;	e[tot].w=w;
	e[tot].nxt=first[u];	first[u]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
	int u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		Add_Edge(u,v,w);	Add_Edge(v,u,w);
		maxL=max(maxL,w);
	}
}

int d[MAXN];	bool vis[MAXN];

void dijkstra()
{
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	priority_queue<Point> q;
	int s=1;	d[s]=0;
	q.push((Point){s,0});
	while(!q.empty())
	{
		int u=q.top().x;	q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=first[u];i!=-1;i=e[i].nxt)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push((Point){v,d[v]});
			}
		}
	}
	/*int s=1;	d[s]=0;	vis[s]=0;
	queue<int> q;	while(!q.empty())	q.pop();
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		vis[u]=0;
		for(int i=first[u];i!=-1;i=e[i].nxt)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}*/
}

int w[MAXM];

bool check(const int& W)
{
	for(int i=1;i<=tot;i++)
		w[i]=e[i].w;
	for(int i=1;i<=tot;i++)
		e[i].w=(e[i].w<=W?0:1);
	dijkstra();
	for(int i=1;i<=tot;i++)
		e[i].w=w[i];
	return d[n]<=k;
}

void work()
{
	int ans=-1;
	int l=0,r=maxL;//l should begin with 0,not 1
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid-1;
			if(ans==-1)
				ans=mid;
			else
				ans=min(ans,mid);
		}
		else
			l=mid+1;
	}
	printf("%d\n",ans);
}

int main()
{
	init();
	work();
	return 0;
}
     