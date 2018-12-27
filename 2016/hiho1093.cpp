#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e7;
struct Edge
{
	int to,nxt;
	int w;
}e[MAXN];
int first[MAXN];
int tot;
int n,m,s,t;

inline void Add_Edge(const int& u,const int& v,const int& w)
{
	e[++tot].nxt=first[u];	first[u]=tot;
	e[tot].w=w; 	e[tot].to=v;
}

void init()
{
	int u,v,w;
	memset(first,-1,sizeof(first));
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		Add_Edge(u,v,w);	Add_Edge(v,u,w);
	}
}

struct Node
{
	int x,d;
	bool operator<(const Node& node)const
	{
		return d>node.d;
	}
};
int d[MAXN];
bool vis[MAXN];
priority_queue<Node> q;

void work()
{
	memset(d,0x3f,sizeof(d));
	q.push((Node){s,0});	d[s]=0;
	while(!q.empty())
	{
		int u=q.top().x;	q.pop();	vis[u]=1;
		for(int i=first[u];i!=-1;i=e[i].nxt)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push(Node{v,d[v]});
			}
		}
	}
	printf("%d\n",d[t]);
}

int main()
{
	init();
	work();
	return 0;
}
     