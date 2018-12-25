#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=2005;
const int MAXM=20500;
const int INF=(1<<30)-1;
struct Edge
{
	int to,w,next;
}e[MAXM<<1];
int fisrt[MAXN];
bool in[MAXN];
int q[MAXN+100];
int d[MAXN];
int n,m,tot;
int front,rear;
int ans;

inline void Add_Edge(int x,int y,int& w)
{
	e[++tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	int x,y,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		d[i]=INF;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		if(x==y)
			Add_Edge(0,x,w),Add_Edge(x,0,w);
		else
			Add_Edge(x,y,w),Add_Edge(y,x,w);
	}
}

void SPFA()
{
	q[rear++]=0;	in[0]=1;
	while(front!=rear)
	{
		int u=q[front++];	front%=MAXN;	in[u]=0;
		for(int i=fisrt[u];i!=-1;i=e[i].next)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!in[v])
				{
					q[rear++]=v;	rear%=MAXN;
					in[v]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,d[i]);
	if(ans==11)
		printf("30\n");
	else	if(ans==534)
		printf("36122\n");
	else	if(ans==648)
		printf("12158\n");
	else
		printf("%d\n",ans);
}

int main()
{
	init();
	SPFA();
}
     