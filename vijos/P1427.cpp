#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
const int MLOG=7;
struct Edge
{
	int to,next,w;
}e[MAXN<<1];
int fisrt[MAXN];
int anc[MAXN][MLOG];
int sum[MAXN][MLOG];
bool flag[MAXN];
int fa[MAXN];
int L[MAXN];
int cost[MAXN];
int n,s,t,tot;

inline void Add_Edge(int& x,int& y,int& w)
{
	e[++tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	int x,y,w;	char a[256];
	memset(fisrt,-1,sizeof(fisrt));
	cin>>n>>s>>t;	s++;	t++;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%s",&x,&y,a);
		if(y==0)	continue;
		w=strlen(a);	flag[x]=1;
		cout<<x<<" "<<y<<endl;
		Add_Edge(x,y,w);	Add_Edge(y,x,w);
	}
	memset(anc,-1,sizeof(anc));
}

void preprocess()
{
	for(int i=0;i<=n;i++)
		anc[i][0]=fa[i],sum[i][0]=cost[i];
	for(int j=1;(1<<j)<n;j++)
		for(int i=1;i<=n;i++)
			if(anc[i][j-1]!=-1)
			{
				int& a=anc[i][j-1];
				anc[i][j]=anc[a][j-1];
				sum[i][j]=sum[i][j-1]+sum[a][j-1];
			}
}

void dfs(int u,int father)
{
	fa[u]=father;
	for(int i=fisrt[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;	int& w=e[i].w;
		if(v!=father)
		{
			L[v]=L[u]+1;	cost[v]=w;
			dfs(v,u);
		}
	}
}

int query(int p,int q)
{
	if(L[p]<L[q])
		swap(p,q);
	int log=1;
	for(;(1<<log)<=L[p];log++);	log--;

	int ans=0;
	for(int i=log;i>=0;i--)
		if(L[p]-(1<<i)>=L[p])
			ans+=sum[p][i],p=anc[p][i];
	if(p==q)	
		return ans;
	for(int i=log;i>=0;i--)
		if(anc[p][i]!=-1&&anc[p][i]!=anc[q][i])
		{
			ans+=sum[p][i];	p=anc[p][i];
			ans+=sum[q][i];	q=anc[q][i];
		}
	ans+=cost[p];
	ans+=cost[q];
	return ans;
}

int main()
{
	init();
	dfs(1,-1);
	for(int i=1;i<=n;i++)
		cout<<cost[i]<<" ";
	cout<<endl;
	preprocess();
	cout<<query(s,t)<<endl;
	return 0;
}
     