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

const int MAXN=205;
const int MAXM=500;
const int INF=1000005;
struct Edge
{
	int to,nxt;
	int cap,flow;
	Edge()
	{
		to=nxt=-1;
		cap=flow=0;
	}
}e[MAXM];
int fisrt[MAXN];
int a,b;
int n,m;
int s,t;
int tot;

inline void Add_Edge(int u,int v,int cap,int flow)
{
	e[tot].to=v; e[tot].cap=cap; e[tot].flow=flow;
	e[tot].nxt=fisrt[u];	fisrt[u]=tot;	tot++;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	read(a);	read(b);
	n=a+b;	m=a;
	s=0;	t=n+1;
	int y,l;
	for(int i=1;i<=m;i++)
	{
		read(l);
		for(int j=1;j<=l;j++)
		{
			read(y);	y+=a;
			Add_Edge(i,y,1,0);	Add_Edge(y,i,0,0);
		}
	}
	for(int i=1;i<=a;i++)
	{
		Add_Edge(s,i,1,0);
		Add_Edge(i,s,0,0);
	}
	for(int i=a+1;i<=n;i++)
	{
		Add_Edge(i,t,1,0);
		Add_Edge(t,i,0,0);
	}
}

int d[MAXN],cur[MAXN];
bool vis[MAXN];
queue<int> q;

bool bfs()
{
	memset(vis,0,sizeof(vis));
	q.push(s);	vis[s]=1;	d[s]=0;
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		for(int i=fisrt[u];i!=-1;i=e[i].nxt)
		{
			Edge& ec=e[i];
			if(!vis[ec.to]&&ec.cap>ec.flow)
			{
				vis[ec.to]=1;
				d[ec.to]=d[u]+1;
				q.push(ec.to);
			}
		}
	}
	return vis[t];
}


int dfs(int x,int a)
{
	if(x==t||a==0)	return a;
	int flow=0,f;
	for(int& i=cur[x];i!=-1;i=e[i].nxt)
	{
		Edge& ec=e[i];
		if(d[x]+1==d[ec.to]&&(f=dfs(ec.to,min(a,ec.cap-ec.flow)))>0)
		{
			ec.flow+=f;
			e[i^1].flow-=f;
			flow+=f;
			a-=f;
			if(a==0)
				break;
		}
	}
	return flow;
}

void maxflow()
{
	int flow=0;
	while(bfs())
	{
		for(int i=s;i<=t;i++)
			cur[i]=fisrt[i];
		flow+=dfs(s,INF);
	}
	out(flow);
}

int main()
{
	init();
	maxflow();
}
     