#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
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

const int MAXN=10005;
const int INF=0x7fffff;
const int MAXM=2000005;
struct Edge
{
	int to,nxt;
	int cap,flow;
	Edge()
	{
		to=nxt=-1;
		cap=flow=0;
	}
}e[MAXM<<1];
int fisrt[MAXN];
int n,m;
int s,t;
int tot;

inline void Add_Edge(int u,int v,int cap,int flow)
{
	e[tot++].to=v;	e[tot].cap=cap;	e[tot].flow=flow;
	e[tot].nxt=fisrt[u];	fisrt[u]=tot;
}

void init()
{
	read(n);	read(m);
	read(s);	read(t);
	int u,v,c;
	memset(fisrt,-1,sizeof(fisrt));
	for(int i=1;i<=m;i++)
	{
		read(u);	read(v);	read(c);
		Add_Edge(u,v,c,0);	Add_Edge(v,u,0,0);
	}
}

bool vis[MAXN];
int cur[MAXN];
int d[MAXN];
queue<int> q;

bool bfs()
{
	memset(vis,0,sizeof(vis));
	q.push(s);
	d[s]=0;	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();	q.pop();
		for(int i=fisrt[x];i!=-1;i=e[i].nxt)
		{
			int& v=e[i].to;	int& cap=e[i].cap;	int& flow=e[i].flow;
			if(!vis[v]&&cap>flow)
			{
				vis[v]=1;
				d[v]=d[x]+1;
				q.push(v);
			}
		}
	}
	return vis[t];
}

int dfs(int x,int a)
{
	if(x==t||a==0)
		return a;
	int flow=0,f;
	for(int& i=cur[x];i!=-1;i=e[i].nxt)
	{
		int& v=e[i].to;	int& cap=e[i].cap;	int& flow=e[i].flow;
		if(d[v]==d[x]+1&&(f=dfs(v,min(a,cap-flow)))>0)
		{
			flow+=f;
			e[i^1].flow-=f;
			flow+=f;
			a-=f;
			if(a==0)
				break;
		}
	}
	return flow;
}

void maxflow(int s,int t)
{
	int flow=0;
	while(bfs())
	{
		memset(cur,0,sizeof(cur));
		flow+=dfs(s,INF);
	}
	out(flow);
}

int main()
{
	init();
	maxflow(s,t);
}
