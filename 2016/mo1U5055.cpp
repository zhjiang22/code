#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long MAXN=2006;
const long long INF=0x7fffff;
const long long MOD=1000000007;
struct Edge
{
	long long to,w,next;
	Edge()
	{
		to=next=-1;
		w=0;
	}
}e[MAXN<<2];
long long fisrt[MAXN];
long long q[MAXN];
long long in[MAXN];
long long d[MAXN];
long long p[MAXN];
long long ans;
long long n,m,t;
long long tot;
long long front,rear;

inline void Add_Edge(long long x,long long y,long long w)
{
	tot++;
	e[tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	long long x,y,w;
	scanf("%d%d%d",&n,&m,&t);
	for(long long i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		Add_Edge(x,y,w);
		Add_Edge(y,x,w);
	}
	for(long long i=1;i<=n;i++)
		d[i]=INF;
}

void SPFA(long long s)
{
	d[s]=0;
	in[s]=1;
	p[s]=0;
	q[rear++]=s;
	while(front!=rear)
	{
		long long x=q[front++];front%=MAXN-1;
		in[x]=0;
		for(long long i=fisrt[x];i!=-1;i=e[i].next)
		{
			long long y=e[i].to;	long long w=e[i].w;
			if(d[y]>d[x]+w||(d[y]==d[x]+w&&p[y]>p[x]+1))
			{
				d[y]=d[x]+w;
				p[y]=p[x]+1;
				if(!in[y])
				{
					q[rear++]=y;
					rear%=(MAXN-1);
					in[y]=1;
				}
			}
		}
	}
	for(long long i=2;i<=n;i++)
		ans+=d[i];
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<i<<"  "<<d[i]<<" "<<p[i]<<endl;
	long long tot=0;
	for(long long i=2;i<=n;i++)
		tot+=p[i];
	t++;
	ans=((((long long)(((2*ans)%MOD)+(tot*(t-1))%MOD)*(long long)(t)))/2)%MOD;
	cout<<ans<<endl;
}

int main()
{
	init();
	SPFA(1);
	return 0;
}
     