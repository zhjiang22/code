/*
好题啊
陷阱蛮多的Orz
提供了一些新的套路23333
第一眼看过去	觉得是个SPFA裸题啊
后面感觉不对	没这么简单
出题人黑良心
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
dist［source］< 0 那么就存在负环，因为dist［source］本来为0，
结果跑了一圈成负的了，那说明有负环。
首先我们看到我们要先处理有没有负权环的问题
这个明显要独立做出来
就是我们先定一个vis数组标记点是否访问过
然后每次对于一个未访问的点
SPFA一下	并在SPFA中把到过的点标记访问过
那么我们可以知道	如果和这个点连通】
那么一定就是能走到(能标记到访问)
所以我们下一次就直接从没有访问过的点继续SPFA
即我们一次SPFA可以处理掉一个SCC中是否有负权环的问题
然后一直SPFA完所有的强连通分量
然后处理完后确定没有环了
我们就可以进行正常的SPFA求出最短路了
Orz因为怕麻烦啊
SPFA两种(一种要用到vis一种不要用到vis)就合在一起了
所以检查完负权环后
就要将vis数组清为0防止被SPFA中的判断vis误伤啊
然后就可以直接暴力做了
裸的SPFA好激动啊
注意一下这里SPFA中的小优化
上面也说了
嗯挺好用的Orz
好题
处理负权边和不连通问题
QAQ
随便读入优化一下飞快
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
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

const int MAXN=1005;
const int MAXM=200005;
const int INF=0x7fffffff;
struct Edge
{
	int to,w,nxt;
	Edge()
	{
		to=nxt=-1;
		w=0;
	}
}e[MAXM];
int fisrt[MAXN];
int tot;
int n,m,s;

inline void Add_Edge(int u,int v,int w)
{
	e[++tot].to=v;	e[tot].w=w;
	e[tot].nxt=fisrt[u];	fisrt[u]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	read(n);	read(m);	read(s);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		read(u);	read(v);	read(w);
		Add_Edge(u,v,w);
	}
}

bool vis[MAXN],inq[MAXN];
int cnt[MAXN];
int dis[MAXN];
queue<int> q;

bool spfa(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	memset(inq,0,sizeof(inq));
	memset(cnt,0,sizeof(cnt));
	while(!q.empty())
		q.pop();
	dis[s]=0;	q.push(s);	inq[s]=1;
	while(!q.empty())
	{
		int u=q.front();	q.pop();	inq[u]=0;
		if(dis[s]<0)
			return 0;
		for(int i=fisrt[u];i!=-1;i=e[i].nxt)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(vis[v])
				continue;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!inq[v])
				{
					q.push(v);	inq[v]=1;
				}
				if(++cnt[v]>n)
					return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
		vis[i]=vis[i]||cnt[i];
	return 1;
}

void check()
{
	for(int i=1;i<=n;i++)
		if(!vis[i])
			if(!spfa(i))
			{
				cout<<-1<<endl;
				exit(0);
			}
			else
				continue;
}

void work()
{
	memset(vis,0,sizeof(vis));
	spfa(s);
	for(int i=1;i<=n;i++)
		if(dis[i]==INF)
			cout<<"NoPath"<<endl;
		else
			out(dis[i]);
}

int main()
{
	init();
	check();
	work();
	return 0;
}
     