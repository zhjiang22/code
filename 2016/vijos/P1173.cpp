/*
好题好题~
看到这道题原型是很容易想到划分型dp的
即我们定义f[i]表示到第i天需要的最小代价
很容易发现是具有最优子结构和无后效性性质的
那么很容易得到这样一个转移方程式
f[i]=min(f[j],f[j]+cost[j+1][i]+k)
其中cost[i][j]表示如果[i,j]这个天数段都一直走同一个路线所需要的最小代价
如果无法做到就是INF
即枚举上一个j改变路线过来
关键是这个cost[][]怎么处理惹
我们可以用最短路来做了
对于读入的不能运输的条件我们只需要用一个数组
nocan[k][t]表示第t天k码头不能运输
那么就可以直接记录下
然后用SPFA跑最短路
即跑一边[t1,t2]这个时间内的最短路
(如果t1到t2都走同一条路的话)
如果有一个是跑不到的就返回INF
我们只需要每次在扩展的时候都只扩展在[t1,t2]都可以运输的点
然后就可以预处理出整个cost[][]
时间就是O(t^2km)
dp的时间是O(t^2)
这里加入一个优化
j从后向前枚举
如果有一个cost[j][i]不能成立了
那么必然cost[j-1][i]也不能成立~
这样就可以直接break
但实际因为t很小了威力不是很大~
好题~涨姿势惹
dp和最短路的结合~！
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=22;
const int MAXT=105;
const int MAXM=450;
const int INF=(1<<28)-1;
struct Edge
{
	int to,w,next;
}e[MAXM<<1];
int fisrt[MAXN];
bool nocan[MAXN][MAXT];
bool in[MAXN];
int cost[MAXT][MAXT];
int d[MAXN];
int f[MAXT];
int t,n,m,k;
int st,tt;
int tot;

inline void Add_Edge(int& x,int& y,int& w)
{
	e[++tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	int x,y,w,p;
	memset(fisrt,-1,sizeof(fisrt));
	scanf("%d%d%d%d",&t,&n,&k,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		Add_Edge(x,y,w);	Add_Edge(y,x,w);
	}
	int d;
	scanf("%d",&d);
	for(int i=1;i<=d;i++)
	{
		scanf("%d%d%d",&p,&x,&y);
		for(int j=x;j<=y;j++)
			nocan[p][j]=1;
	}
}

bool judge(int p)
{
	for(int i=st;i<=tt;i++)
		if(nocan[p][i])
			return 0;
	return 1;
}

int SPFA(int x,int y)
{
	st=x;	tt=y;
	if(!judge(1))
		return INF;
	queue<int> q;
	for(int i=1;i<=n;i++)
		d[i]=INF;
	d[1]=0;		in[1]=1;	q.push(1);
	while(!q.empty())
	{
		int u=q.front();	q.pop();	in[u]=0;
		for(int i=fisrt[u];i!=-1;i=e[i].next)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(!judge(v))
				continue;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!in[v])
				{
					in[v]=1;
					q.push(v);
				}
			}
		}
	}
	if(d[n]==INF)
		return INF;
	else
		return d[n]*(y-x+1);
}

int main()
{
	init();
	for(int i=1;i<=t;i++)
		for(int j=i;j<=t;j++)
			cost[i][j]=SPFA(i,j);
	f[0]=0;
	for(int i=1;i<=t;i++)
		f[i]=cost[1][i];
	for(int i=2;i<=t;i++)
		for(int j=i-1;j>=1;j--)
			if(cost[j+1][i]!=INF)
				f[i]=min(f[i],f[j]+cost[j+1][i]+k);
			else
				break;
	cout<<f[t]<<endl;
	return 0;
}
     