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

const int MAXN=100005;
const int MAXM=2000005;
struct Edge
{
	int to,nxt;
	int w;
}e[MAXM];
int fisrt[MAXN];
int n,m,tot;
int s,t;

inline void Add_Edge(int& u,int& v,int& w)
{
	e[++tot].nxt=fisrt[u];	fisrt[u]=tot;
	e[tot].to=v;	e[tot].w=w;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	int x,y,w;
	read(s);	read(t);
	for(int i=1;i<=m;i++)
	{
		read(x);	read(y);	read(w);
		Add_Edge(x,y,w);	Add_Edge(y,x,w);
	}
}

bool inq[MAXN];
int dis[MAXN];
queue<int> q;

void SPFA()
{
	while(!q.empty())
		q.pop();
	memset(inq,0,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	q.push(s);	inq[s]=1;	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		inq[u]=0;
		for(int i=fisrt[u];i!=-1;i=e[i].nxt)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!inq[v])
				{
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}

void work()
{
	SPFA();
	out(dis[t]);
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		work();
	}
	return 0;
}
     