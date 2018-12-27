/*
一道蛮简单的差分约束的感觉OTZ
然而有很多细节和技巧可以学习
首先我们要先了解一下差分约束然后再来做这题
我们可以考虑如果输入a,b,w w==1	那么a到b连一条权值1的边
w==-1 y到x连一条权值1的边
w==0  则两个点连一条权值0的无向边就好了
那么我们建立好了这个差分系统时
我们就可以跑一边最长路了
因为是最长路所以d[]初始化要是负无穷大
和最短路一样但是是对立的
如果有一个正权环	那么我们肯定可以沿着这条正权环绕啊绕得到更长的最长路
所以不存在正确的k时就是不存在最长路的情况
即比如a到b权1(a比b大)	b到c权1(b比c大)
而c到a也权1(c比a大)	自然是无解的
所以我们就跑SPFA最长路+判负环就好了
然后就是我们可以看到
SPFA是求单源最短路径
而这道题并没有明确的起点终点
所以要得到每个点的d[]取最大值了
那么我们怎么做到呢？
这里有一个小技巧了
我们设置一个虚的源点0
然后再从0到每个顶点连一条权值为0的有向边
这样就可以求出这个所有的d[]的最大值了
OTZ被坑了很久一直过不了自己的数据包
想了半天
长见识了
然后一开始写的是STL队列	后来换成了手写循环队列练习一下Orz
窝好弱啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1050;
const int MAXV=20005;
const int INF=0x7ffffff;
struct Edge
{
	int to,w,next;
	Edge()
	{
		to=next=w=-1;
	}
}e[MAXV];
int first[MAXN];
int cnt[MAXN];
int d[MAXN];
int q[MAXN];
bool in[MAXN];
int front,rear;
int n,m;
int tot;
int ans;

void inline Add_Edge(int x,int y,int w)
{
	tot++;
	e[tot].to=y;
	e[tot].w=w;
	e[tot].next=first[x];
	first[x]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
	int x,y,w;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		if(w==1)
			Add_Edge(x,y,1);
		else	if(w==-1)
			Add_Edge(y,x,1);
		else	if(w==0)
			Add_Edge(x,y,0),
			Add_Edge(y,x,0);
	}
	for(int i=1;i<=n;i++)//设一个虚源点0作为SPFA起点
		Add_Edge(0,i,0);
}

void SPFA(int s)
{
	for(int i=1;i<=n;i++)
		d[i]=-INF;
	d[s]=0;
	q[rear++]=s;
	in[s]=1;
	cnt[s]++;
	while(front!=rear)
	{
		int x=q[front];
		front=(front+1)%1005;	
		in[x]=0;
		for(int i=first[x];i!=-1;i=e[i].next)
		{
			int u=e[i].to;	int w=e[i].w;
			if(d[u]<d[x]+w)//最长路
			{
				d[u]=d[x]+w;
				if(!in[u])
				{
					q[rear]=u;
					rear=(rear+1)%1005;
					in[u]=1;
					if(++cnt[u]>n)
					{
						cout<<"NO"<<endl;
						exit(0);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,d[i]);
	cout<<ans<<endl;
}

int main()
{
	init();
	SPFA(0);
	return 0;
}