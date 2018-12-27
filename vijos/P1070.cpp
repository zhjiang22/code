/*
经典题啊~次小生成树问题~
在lrj的训练指南上也有啦~
代码写得好丑啊第一次写23333
我们先用Kruskal跑一遍最小生成树
然后这样的话我们根据这个加的边建立起一棵真正的树
并且转换为有根树
这样我们对于树上任意两点我们都可以求出它们唯一路径上的最长边
即f[u][v]表示u到v路径上的最大边权
这里可以直接O(n^2)dfs也可以直接上树上倍增(nlogn)
这样子的话我们就可以直接枚举未加入最小生成树中的边
然后尝试加入~
MST有的边交换性质(次小一定是最小交换一条边来的)
那么对于新加入的边(u,v,w)
我们尝试将此边加入MST中
那么必然是换掉加入后u,v这个环上的除了这条边的最大权值最好
就是我们的f[u][v]
那么这样我们就可以直接O(m)枚举
所以复杂度就是预处理的O(n^2)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=505;
const int MAXM=250002;
const int INF=(1<<30)-1;
struct Edge1
{
	int from,to,w;
	bool operator <(const Edge1& b)const
	{
		return w<b.w;
	}
}e1[MAXM];
struct Edge
{
	int from,to,w,next;
}e[MAXN<<1];
int fisrt[MAXN];//Edges
int pa[MAXN];//bingcha~
int f[MAXN][MAXN];
int fa[MAXN];//Tree
bool vis[MAXN];
bool have[MAXM];
int n,m,tot;
int ans1,ans2;

inline int find(int& x)
{
	return pa[x]==x?x:pa[x]=find(pa[x]);
}

inline void Add_Edge(int& x,int& y,int& w)
{
	e[++tot].from=x;	e[tot].to=y;
	e[tot].w=w;		e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e1[i].from,&e1[i].to,&e1[i].w);
	for(int i=1;i<=n;i++)
		pa[i]=i;
}

void Kruskal()
{
	sort(e1+1,e1+m+1);
	int c=0;
	for(int i=1;i<=m;i++)
	{
		int& x=e1[i].from;	int& y=e1[i].to;	int& w=e1[i].w;
		int fx=find(x);	int fy=find(y);
		if(fx!=fy)
		{
			pa[fx]=fy;	have[i]=1;
			Add_Edge(x,y,w);	Add_Edge(y,x,w);
			c++;	ans1+=w;
		}	
		if(c>=n-1)
			break;	
	}
	if(c!=n-1)
		printf("Cost: -1\n");
	else
		printf("Cost: %d\n",ans1);
}

void dfsroot(int u,int father)
{
	fa[u]=father;
	for(int i=fisrt[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;	int& w=e[i].w;
		if(!fa[v]&&v!=father)
		{
			f[u][v]=f[v][u]=w;
			dfsroot(v,u);
		}
	}
}

void dfs(int u)
{
	int& v=fa[u];
	for(int i=1;i<=n;i++)
		if(vis[i])
			f[i][u]=f[u][i]=max(f[i][v],f[u][v]);
	vis[u]=1;
	for(int i=fisrt[u];i!=-1;i=e[i].next)
		if(fa[e[i].to]==u)
			dfs(e[i].to);
}

void NextKruskal()
{
	ans2=INF;
	for(int i=1;i<=m;i++)
		if(!have[i])
		{
			ans2=min(ans2,ans1-f[e1[i].from][e1[i].to]+e1[i].w);
		}
	if(ans2==INF)
		printf("Cost: -1\n");
	else
		printf("Cost: %d\n",ans2);
}

int main()
{
	init();
	Kruskal();
	dfsroot(1,-1);
	dfs(1);
	NextKruskal();
}
     