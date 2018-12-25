#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
const int MAXM=200005;
const int INF=0x7fffff;
const int MOD=100003;
struct Edge
{
	int to,next;
	Edge()
	{
		to=next=-1;
	}
}e[MAXM<<1];
int first[MAXN];
int q[MAXN];
int d[MAXN];
int p[MAXN];
bool in[MAXN];
int n,m,tot;
int front,rear;
int ans;

inline void Add_Edge(int x,int y)
{
	tot++;
	e[tot].to=y;
	e[tot].next=first[x];	first[x]=tot;
}

void init()
{
	int x,y;
	cin>>n>>m;
	memset(first,-1,sizeof(first));
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		Add_Edge(x,y);
		Add_Edge(y,x);
	}
	for(int i=1;i<=n;i++)
		d[i]=INF;
}

void SPFA(int s)
{
	q[rear++]=s;	in[s]=1;	d[s]=0;	p[1]=1;
	while(front!=rear)
	{
		int u=q[front++];	front%=(MAXN-1);
		in[u]=0;
		for(int i=first[u];i!=-1;i=e[i].next)
		{
			int v=e[i].to;
			if(d[v]>d[u]+1)
			{
				d[v]=d[u]+1;
				p[v]=p[u];
				if(!in[v])
				{
					in[v]=1;
					q[rear++]=v;	rear%=(MAXN-1);
				}
			}
			else	if(d[v]==d[u]+1)
			{
				p[v]=(p[v]+p[u])%MOD;
			}
		}
	}
}

void out()
{
	for(int i=1;i<=n;i++)
		cout<<p[i]<<endl;
}

int main()
{
	init();
	SPFA(1);
	out();
	return 0;
}
     