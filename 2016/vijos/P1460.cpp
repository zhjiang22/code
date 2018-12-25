#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
const int Mlog=15;
const int INF=(1<<30)-1;
struct Edge
{
	int to,next,w;
}e[MAXN<<1];
int fisrt[MAXN];
int fa[MAXN],L[MAXN];
int cost[MAXN];
int anc[MAXN][Mlog];
long long sumcost[MAXN][Mlog];
long long ans,sum;
int n,m,tot;

inline void Add_Edge(int& x,int& y,int& w)
{
	e[++tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	int x,y,w;
	memset(fisrt,-1,sizeof(fisrt));
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		Add_Edge(x,y,w);	Add_Edge(y,x,w);
	}
	memset(anc,-1,sizeof(anc));
}

void dfs(int u,int f)
{
	fa[u]=f;
	for(int i=fisrt[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;	int& w=e[i].w;
		if(v!=f)
		{
			L[v]=L[u]+1;	cost[v]=w;
			dfs(v,u);
		}
	}
}

void initfa()
{
	for(int i=1;i<=n;i++)
		anc[i][0]=fa[i],sumcost[i][0]=cost[i];
	for(int j=1;(1<<j)<n;j++)
		for(int i=1;i<=n;i++)
			if(anc[i][j-1]!=-1)
			{
				int& a=anc[i][j-1];
				anc[i][j]=anc[a][j-1];
				sumcost[i][j]=sumcost[i][j-1]+sumcost[a][j-1];
			}
}

long long query(int p,int q)
{
	if(L[p]>L[q])
		return -1;
	swap(p,q);
	int logg=1;
	long long ans=0;
	for(;(1<<logg)<=L[p];logg++);	logg--;
	for(int i=logg;i>=0;i--)
		if(L[q]+(1<<i)<=L[p])
		{
			ans+=sumcost[p][i];
			p=anc[p][i];
		}
	if(p!=q)
		return -1;
	return ans;
}

void question()
{
	int p,q;
	long long w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&q);
		w=query(p,q);
		if(w!=-1)
		{
			ans++;
			sum+=w;
		}
	}
	cout<<ans<<endl;
	cout<<sum<<endl;
}

int main()
{
	init();
	dfs(1,-1);
	initfa();
	question();
}
     