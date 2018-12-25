#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

char rd;	int pn;
template<typename Type>
inline void read(Type& v)
{
	pn=1;
	while((rd=getchar())<'0'||rd>'9')
		if(rd=='-')
			pn=-1;
	v=rd-'0';
	while((rd=getchar())>='0'&&rd<='9')
		v=v*10+rd-'0';
	v*=pn;
}
template<typename Type>
inline void out(Type v,bool c=1)
{
	if(v==0)
		putchar(48);
	else  
    {
    	if(v<0)
    	{
    		putchar('-');
    		v=-v;
    	}
    	int len=0,dg[20];  
    	while(v>0)
    	{
    		dg[++len]=v%10;
    		v/=10;
    	}  
    	for(int i=len;i>=1;i--)
    		putchar(dg[i]+48);  
    }
    if(c)
    	putchar('\n');
    else
    	putchar(' ');
}
const int MAXN=105;
const int MAXM=2005;
const int INF=(1<<30)-1;
struct Edge
{
	int from,to,next,cap,flow;
}e[MAXM];
int fisrt[MAXN];//Edges
int cur[MAXN],d[MAXN];//Dinic
int n,m,k,tot;
int s,t;

inline void Add_Edge(int& x,int& y,int cap)
{
	e[tot].from=x;	e[tot].to=y;	e[tot].cap=cap;
	e[tot].next=fisrt[x];	fisrt[x]=tot++;
}

void init()
{
	int x,y,w;
	memset(fisrt,-1,sizeof(fisrt));
	read(n);	read(m);
	for(int i=1;i<=m;i++)
	{
		read(x);	read(y);	read(w);
		Add_Edge(x,y,w);	Add_Edge(y,x,0);
		Add_Edge(y,x,w);	Add_Edge(x,y,0);
	}
	s=1;	t=n+1;
	read(k);
	for(int i=1;i<=k;i++)
	{
		read(x);
		Add_Edge(x,t,INF);	Add_Edge(t,x,0);
	}
}

bool inq[MAXN];
queue<int> q;
//bfs
bool bfs()
{
	memset(inq,0,sizeof(inq));
	q.push(s);	d[s]=0;	inq[s]=1;
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		for(int i=fisrt[u];i!=-1;i=e[i].next)
		{
			int& v=e[i].to;	int& cap=e[i].cap;	int& flow=e[i].flow;
			if(!inq[v]&&cap>flow)
			{
				inq[v]=1;
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return inq[t];
}

int dfs(int u,int minflow)
{
	if(u==t||minflow==0)
		return minflow;
	int add_flow=0,f;
	for(int& i=cur[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;	int& cap=e[i].cap;	int& flow=e[i].flow;
		if(d[v]==d[u]+1&&(f=dfs(v,min(minflow,cap-flow)))>0)
		{
			flow+=f;	e[i^1].flow-=f;
			add_flow+=f;	minflow-=f;
			if(minflow==0)
				break;
		}
	}
	return add_flow;
}

void Dinic()
{
	int maxflow=0;
	while(bfs())
	{
		for(int i=1;i<=t;i++)
			cur[i]=fisrt[i];
		maxflow+=dfs(s,INF);
	}
	out(maxflow);
}

int main()
{
	init();
	Dinic();
}
     