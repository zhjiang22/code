#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN=1005;
const int MAXM=20005;
const int MAXW=10005;
struct Edge
{
	int to,nxt;
	int w;
}e[MAXM];
int first[MAXN];
int minw[MAXN];
int g[MAXN];
int n,m;
int tot;
int t;

inline void Add_Edge(const int& u,const int& v,const int& w)
{
	e[++tot].to=v;	e[tot].w=w;
	e[tot].nxt=first[u];	first[u]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
	memset(minw,0x3f,sizeof(minw));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&g[i]);
	int x,y,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		x++;	y++;
		Add_Edge(x,y,w);	Add_Edge(y,x,w);
		minw[x]=min(minw[x],w);	minw[y]=min(minw[y],w);
	}
}

struct Point
{
	int pos;
	int fule;
	int cost;
	bool operator<(const Point& p)const
	{
		return cost>p.cost;
	}
};

bool vis[MAXN][MAXW];

void bfs(int c,int s,int t)
{
	memset(vis,0,sizeof(vis));
	Point S={s,0,0};
	priority_queue<Point> q;
	while(!q.empty())
		q.pop();
	q.push(S);
	vis[s][0]=1;
	while(!q.empty())
	{
		Point now=q.top();	q.pop();
		int& u=now.pos;	
		int& fule=now.fule;	int& cost=now.cost;
		vis[u][fule]=1;
		//cout<<u<<" "<<fule<<" "<<cost<<endl;
		if(u==t)
		{
			printf("%d\n",cost);
			return;
		}
		if(fule<c)
			q.push((Point){u,fule+1,cost+g[u]});
		for(int i=first[u];i!=-1;i=e[i].nxt)
		{
			int& v=e[i].to;	int & w=e[i].w;
			if(fule<w)
				continue;
			if(!vis[v][fule-w])
				q.push((Point){v,fule-w,cost});
		}
	}
	printf("impossible\n");
}

void work()
{
	cin>>t;
	int c,x,y;
	while(t--)
	{
		scanf("%d%d%d",&c,&x,&y);
		x++;	y++;
		bfs(c,x,y);
	}
}

int main()
{
	init();
	work();
	return 0;	
}