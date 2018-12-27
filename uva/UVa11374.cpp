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

const int MAXN=10005;
const int MAXM=100005;
struct Edge
{
	int to,nxt,w;
	Edge()
	{
		to=nxt=-1;
		w=0;
	}
}e[MAXM];
int first[MAXN];
Edge fur_edge[MAXM];
int n,m,k;
int s,t;
int tot,fur_tot;

int first_blod;

inline void Add_Edge(int& u,int& v,int& w)
{
	e[++tot].nxt=first[u];	first[u]=tot;
	e[tot].to=v;	e[tot].w=w;
}

void init()
{
	memset(first,-1,sizeof(first));
	tot=0;	fur_tot=0;
	int x,y,w;
	read(m);
	for(int i=1;i<=m;i++)
	{
		read(x);	read(y);	read(w);
		Add_Edge(x,y,w);	Add_Edge(y,x,w);
	}
	read(k);
	for(int i=1;i<=k;i++)
	{
		read(x);	read(y);	read(w);
		fur_edge[++fur_tot].nxt=x;	fur_edge[fur_tot].to=y;	
		fur_edge[fur_tot].w=w;
	}
}

int ds[MAXN];
int dt[MAXN];
bool inq[MAXN];
int ps[MAXN],pt[MAXN];

void SPFA(int d[],int p[],int s)
{
	queue<int> q;
	for(int i=1;i<=n;i++)
		d[i]=999999999;
	memset(inq,0,sizeof(inq));
	q.push(s);	d[s]=0;	inq[s]=1;
	while(!q.empty())
	{
		int u=q.front();	q.pop();	inq[u]=0;
		for(int i=first[u];i!=-1;i=e[i].nxt)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				p[v]=u;
				if(!inq[v])
				{
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}

void out1()
{
	int cur=t;
	int pis[MAXN];
	int l=0;
	while(cur!=s)
	{
		pis[++l]=cur;
		cur=ps[cur];
	}
	pis[++l]=s;
	printf("%d",pis[l]);
	for(int i=l-1;i>=1;i--)
		printf(" %d",pis[i]);
	printf("\n");
}

void out2(int k)
{
	int cur=t;
	int pis[MAXN];
	int l=0;
	while(cur!=k)
	{
		pis[++l]=cur;
		cur=ps[cur];
	}
	pis[++l]=cur;
	int piss[MAXN];
	int ll=0;
	cur=s;
	while(cur!=k)
	{
		piss[++ll]=cur;
		cur=pt[cur];
	}
	if(ll!=0)
	{
		printf("%d",piss[1]);
		for(int i=2;i<=ll;i++)
			printf(" %d",piss[i]);
		for(int i=l;i>=1;i--)
			printf(" %d",pis[i]);
		printf("\n");
	}
	else
	{
		printf("%d",pis[l]);
		for(int i=l-1;i>=1;i--)
			printf(" %d",pis[i]);
		printf("\n");
	}
}


void work()
{
	if(first_blod)
		cout<<endl;
	first_blod=1;
	SPFA(ds,ps,s);
	SPFA(dt,pt,t);
	int ans=min(ds[t],dt[s]);
	int cur=-1;	int a=0;
	for(int i=1;i<=k;i++)
	{
		int& x=fur_edge[i].nxt;	int& y=fur_edge[i].to;
		int& w=fur_edge[i].w;
		if(ans>ds[x]+w+dt[y])
		{
			ans=ds[x]+w+dt[y];
			cur=i;	a=0;
		}
		if(ans>ds[y]+w+dt[x])
		{
			ans=ds[y]+w+dt[x];
			cur=i;	a=1;
		}
	}
	if(cur!=-1)
	{
		Add_Edge(fur_edge[cur].nxt,fur_edge[cur].to,fur_edge[cur].w);
		Add_Edge(fur_edge[cur].to,fur_edge[cur].nxt,fur_edge[cur].w);
		SPFA(ds,ps,s);
		SPFA(dt,pt,t);
	}
	if(cur==-1)
		out1();
	else	if(a==0)
		out2(fur_edge[cur].nxt);
	else
		out2(fur_edge[cur].to);
	if(cur==-1)
		printf("Ticket Not Used\n");
	else	if(a==0)
		out(fur_edge[cur].nxt);
	else
		out(fur_edge[cur].to);
	out(ans);
}

int main()
{
	while(scanf("%d%d%d",&n,&s,&t)!=EOF)
	{
		init();
		work();
	}
	return 0;
}
