/*
好题啊	陷阱蛮多的
提供了一些新的套路
第一眼看过去	觉得是个SPFA裸题啊
后面感觉不对	没这么简单
当输入的图不是连通图时，SPFA(s)能做的就只是找出源点s所在的连通分量中的负环而已。
也就是说如果图中存在环，但不在源点所在的连通分量内的话，就会输出一堆的NoPath，
而不是－1，从此WA没救。
解决方案：
添加一个数组vis，来确定某个点是否访问过
（因为如果不在源点的连通分量内的点在SPFA的过程中时不会访问到的）。
然后每一个没有访问过的点都来一遍SPFA，以此来检查是否存在负环。
每次SPFA完了之后再将每个在这一次SPFA中 访问过的点的vis设为true，判断的标准：
是否进入过队列。
小优化：
d［source］< 0 那么就存在负环，因为dist［source］本来为0，
结果跑了一圈成负的了，那说明有负环。
怎么理解呢
首先我们看到我们要先处理有没有负权环的问题
这个明显要独立做出来
就是我们先定一个vis数组标记点是否访问过
然后每次对于一个未访问的点
SPFA一下	并在SPFA中把到过的点标记访问过
那么我们可以知道	如果和这个点连通
那么一定就是能走到(能标记到访问)
所以我们下一次就直接从没有访问过的点继续SPFA
即我们一次SPFA可以处理掉一个SCC中是否有负权环的问题
然后一直SPFA完所有的强连通分量
然后处理完后确定没有环了
我们就可以进行正常的SPFA求出最短路了
SPFA两种(一种要用到vis一种不要用到vis)就合在一起了
所以检查完负权环后
就要将vis数组清为0防止被SPFA中的判断vis误伤
然后就可以直接暴力做了
注意一下这里SPFA中的小优化
处理负权边和不连通问题
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=1005;
const int MAXM=100010;
const int INF=0x7fffffff;
struct Edge
{
	int to,w,next;
}e[MAXM];
int fisrt[MAXN];
int cnt[MAXN];
bool in[MAXN],vis[MAXN];
int d[MAXN];
int n,m,tot;
int s;
queue<int> q;

void inline Add_Edge(int& x,int& y,int& w)
{
	e[++tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	memset(vis,0,sizeof(vis));
	memset(fisrt,-1,sizeof(fisrt));
	scanf("%d%d%d",&n,&m,&s);
	int x,y,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		Add_Edge(x,y,w);
	}
}

bool SPFA(int s)
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
		d[i]=INF;
	d[s]=0;
	q.push(s);	in[s]=1;	cnt[s]++;
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		in[u]=false;

		if(d[s]<0)//SPFA的一个优化	
			return false;

		for(int i=fisrt[u];i!=-1;i=e[i].next)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(vis[v])
				continue;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!in[v])
				{
					q.push(v);
					in[v]=1;
				}
				if(++cnt[v]>n)
					return false;
			}
		}
	}
	for(int i=1;i<=n;i++)
		vis[i]=cnt[i]||vis[i];
	return true;
}

void check()//检查是否有负权回路
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			if(!(SPFA(i)))
			{
				cout<<-1<<endl;
				exit(0);
			}
		}
	memset(vis,0,sizeof(vis));//最短路时需要清零
}

void out()
{
	for(int i=1;i<=n;i++)
		if(d[i]==INF)
			cout<<"NoPath"<<endl;
		else	
			cout<<d[i]<<endl;
}

int main()
{
	init();
	check();
	SPFA(s);
	out();
}
     