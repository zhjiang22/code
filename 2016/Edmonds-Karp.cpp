#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=1005;
const int MAXM=6006;
const int INF=(1<<30)-1;
struct Edge
{
	int from,to,cap,flow;
	int next;
}e[MAXM<<1];
int a[MAXN],pre[MAXN];
int fisrt[MAXN];
int n,m,tot;
int s,t;
queue<int> q;

inline void Add_Edge(int x,int y,int cap)
{
	e[tot].from=x;	e[tot].to=y;	e[tot].cap=cap;
	e[tot].next=fisrt[x];	fisrt[x]=tot++;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	cin>>n>>m;
	int x,y,cap;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>cap;
		Add_Edge(x,y,cap);
		Add_Edge(y,x,0);//容量要为0
	}
	cin>>s>>t;
}

int EdmondsKarp()
{
	int flow=0;
	for(;;)
	{
		while(!q.empty())//清空队列
			q.pop();
		memset(a,0,sizeof(a));
		a[s]=INF;	q.push(s);//源点入队
		while(!q.empty())//开始bfs
		{
			int u=q.front();	q.pop();
			for(int i=fisrt[u];i!=-1;i=e[i].next)
			{
				int& v=e[i].to;	int& flow=e[i].flow;	int& cap=e[i].cap;
				if(!a[v]&&cap>flow)
				{
					pre[v]=i;
					a[v]=min(a[u],cap-flow);
					q.push(v);
				}
			}
			if(a[t])	break;//到过t了可以直接break
		}
		if(!a[t])	break;//无法增广~
		for(int u=t;u!=s;u=e[pre[u]].from)
		{
			e[pre[u]].flow+=a[t];
			e[pre[u]^1].flow-=a[t];//反向边
		}
		flow+=a[t];
	}
	return flow;
}

int main()
{
	init();
	cout<<EdmondsKarp()<<endl;
	return 0;
}
     