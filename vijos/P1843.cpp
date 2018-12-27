/*
第一题LCA~话说这几年NOIPT3是不是偏爱LCA了....
Orz原来一直懒得学看博客发现看不懂啊
然后发现lrj的训练指南上正好有这题~！
(NOIP难道是借鉴UVA?)
终于把他弄懂了~
这道题其实就是用一个最大生成树然后再LCA弄两下就好啦
很多神犇都说的比我好啊~
窝就不班门弄斧写题解了(网上和lrj都说的很好了~)
其实LCA就是巧妙地利用了二进制降低复杂度了
开熏竟然写出来了
虽然RE了两次原因是*标记处n从1开始循环了..还有没有判断x=-1时
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
const int MAXM=100005;
const int MAXLOG=17;
const int INF=(1<<30)-1;
struct Edge
{
	int from,to,w,next;
	bool operator < (const Edge& b)	const
	{
		return w>b.w;
	}
}e[MAXM],e1[MAXM];
int fisrt[MAXN];
int fa[MAXN],cost[MAXN],L[MAXN];
int anc[MAXN][MAXLOG];
int mincost[MAXN][MAXLOG];
int pa[MAXN];
int n,m,q,tot,edges;

int find(int x)
{
	return pa[x]==x?x:pa[x]=find(pa[x]);
}

inline void Add_Edge1(int &x,int& y,int& w)
{
	e1[++edges]=(Edge){x,y,w,0};
}

inline void Add_Edge(int& x,int& y,int& w)
{
	e[++tot].from=x;	e[tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	int x,y,w;
	memset(fisrt,-1,sizeof(fisrt));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		x--;	y--;
		Add_Edge1(x,y,w);
	}
	scanf("%d",&q);
	memset(mincost,0x3f,sizeof(mincost));
	memset(anc,-1,sizeof(anc));
}

void Kruskal()
{
	for(int i=0;i<=n;i++)
		pa[i]=i;
	sort(e1+1,e1+edges+1);
	int fx,fy;
	int tot=0;
	for(int i=1;i<=edges;i++)
	{
		int& x=e1[i].from;	int& y=e1[i].to;	int& w=e1[i].w;
		fx=find(x);	fy=find(y);
		if(fx!=fy)
		{
			Add_Edge(x,y,w);	Add_Edge(y,x,w);
			pa[fx]=fy;
			tot++;
		}
		if(tot>=n-1)	
			break;
	}
}

void dfs(int u,int f)
{
	fa[u]=f;
	for(int i=fisrt[u];i!=-1;i=e[i].next)
		if(!fa[e[i].to]&&e[i].to!=f)
		{
			L[e[i].to]=L[u]+1;	cost[e[i].to]=e[i].w;
			dfs(e[i].to,u);
		}
}

void preprocess()
{
	for(int i=0;i<n;i++)
		anc[i][0]=fa[i],mincost[i][0]=cost[i];
	for(int j=1;(1<<j)<n;j++)
		for(int i=0;i<=n;i++)//*
			if(anc[i][j-1]!=-1)
			{
				int& x=anc[i][j-1];
				anc[i][j]=anc[x][j-1];
				mincost[i][j]=min(mincost[i][j-1],mincost[x][j-1]);
			}
}


void query(int p,int q)
{
	if(L[p]<L[q])
		swap(p,q);
	int mlog=1;
	for(;(1<<mlog)<=L[p];mlog++);	mlog--;//找到这个最大临界值
	int ans=INF;
	for(int i=mlog;i>=0;i--)//将p提到和q一个高度
		if(L[p]-(1<<i)>=L[q])
		{
			ans=min(ans,mincost[p][i]);
			p=anc[p][i];
		}
	if(p==q)
	{
		cout<<ans<<endl;
		return;
	}
	for(int i=mlog;i>=0;i--)
		if(anc[p][i]!=-1&&anc[p][i]!=anc[q][i])
		{
			ans=min(ans,mincost[p][i]);	ans=min(ans,mincost[q][i]);
			p=anc[p][i];	q=anc[q][i];
		}
	ans=min(ans,cost[p]);
	ans=min(ans,cost[q]);
	cout<<ans<<endl;
}

void question()
{
	int x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		x--;	y--;
		if(find(x)!=find(y))
			printf("-1\n");
		else
			query(x,y);
	}
}

int main()
{
	init();
	Kruskal();
	dfs(1,-1);
	preprocess();
	question();
	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXN=2000;
int d[MAXN][MAXN];
int n,m;
int q;

void init()
{
	memset(d,-1,sizeof(d));
	cin>>n>>m;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		d[x][y]=d[y][x]=max(d[x][y],z);
	}
}

void query()
{
	cin>>q;
	int x,y;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<d[x][y]<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	init();
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(d[i][k]!=-1&&d[k][j]!=-1)
				{
					if(d[i][j]==-1)
						d[i][j]=min(d[i][k],d[k][j]);
					else
						d[i][j]=max(d[i][j],min(d[i][k],d[k][j]));
				}
	query();
	return 0;
}
*/   