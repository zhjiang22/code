/*
第一题网络流~OTZ!
很明显这就是个最小割问题咯~
窝们都知道的~最小割=最大流
所以直接求个裸的最大流就好啦~
数据范围很小但未了练习还是写了邻接表~~
果然数据太小EK都能差点秒杀~
害怕
我们可以对于读入的边建边容量就是他的距离~
然后设置一个炒鸡(超级)源点n+1
然后对于每一个传送点连一条边到n+1容量为INF
那么我们直接求出1到n+1的最大流就好啦~
为什么可以这样呢？
因为最大流的值受限于最小割
先定义D(u,v)，表示从u到v的路径上的最小边权
先考虑只有一个传送点吧
首先肯定u到v可能存在多条不同的路径
暂且假设有两条不相交的路径
那么答案显然是 两条路径的D(u,v)
此时用网络流来解决这个问题
那么设边权为容量
因为一条路径上的流量会受限于这条路径的最小边权
所以答案也是两条路径的D(u,v)的和
接下来考虑一下，这两条路径是有交集的
也就是说两条路径有重合部分
考虑一下两条路径的第一个相交点w	
那么到w的最大流就是两条路径的D(u,w)的和
再考虑w到v	w到v的最大流要不就是两条D(u,v)的和，要不就是D(w,v)，取其中的更小值
其实也就是对应了两种监控方法：在两条路径上分别监控，或在交集部分监控
最优解就是两种方案的花费的最小值
回到原问题的话
其实可以不建超级汇点t	可以求1到传送点1,2,3,...n的最大流(最小割)
它们之和就是答案

找一个边集	
这个边集的一个端点在S，也就是源点所在的点集，另一个端点在T，也就是汇点所在的点集
那么去掉所有这些边，S和T不连通
原问题其实是：找这样一个边集，并使边集权值最小
这样的边集就是最小割
因为监控的含义是：这条边不能通过，换句话说，就是删掉这条边
这个边集应该满足：一个端点在S，另一个端点在T
因为如果连通的话，说明从源点s还可以到达T中的点
然后又可以证明最小割=最大流
换句话说就是	我们要让所有的传送点和T在一个集合内
那么我们将传送点和T一连无限容量	那么肯定就要在T集合内了
不然不可能是最小割~！
而我们知道S集合和T集合石不可能连通的
如果连通的话说明从源点s还可以到达T中的点
那么肯定是还可以继续增广的
所以就直接求出最小割就好啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=105;
const int MAXM=2005;
const int INF=(1<<30)-1;
struct Edge
{
	int from,to,cap,flow;
	int next;
}e[MAXM];
int fisrt[MAXN];
int a[MAXN],pre[MAXN];
int n,m,k,tot;
int s,t;

inline void Add_Edge(int x,int y,int cap)
{
	e[tot].from=x;	e[tot].to=y;	e[tot].cap=cap;
	e[tot].next=fisrt[x];	fisrt[x]=tot++;
}

void init()
{
	int x,y,w;
	memset(fisrt,-1,sizeof(fisrt));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		Add_Edge(x,y,w);	Add_Edge(y,x,0);
		Add_Edge(y,x,w);	Add_Edge(x,y,0);
	}
	s=1;	t=n+1;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x;
		Add_Edge(x,t,INF);	Add_Edge(t,x,0);
	}
}

int EK()
{
	int flow=0;
	for(;;)
	{
		memset(a,0,sizeof(a));	queue<int> q;
		q.push(1);	a[1]=INF;
		while(!q.empty())
		{
			int u=q.front();	q.pop();
			for(int i=fisrt[u];i!=-1;i=e[i].next)
			{
				int& v=e[i].to;	int& cap=e[i].cap;	int& flow=e[i].flow;
				if(!a[v]&&flow<cap)
				{
					pre[v]=i;
					a[v]=min(a[u],cap-flow);
					q.push(v);
				}
			}
			if(a[t])	break;
		}
		if(!a[t])	return flow;
		for(int i=t;i!=s;i=e[pre[i]].from)
		{
			e[pre[i]].flow+=a[t];
			e[pre[i]^1].flow-=a[t];
		}
		flow+=a[t];
	}
}

int main()
{
	init();
	cout<<EK()<<endl;
	return 0;
}
     