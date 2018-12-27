/*
好题Orz..
第一道搜索题自己想出思路后在半个小时内两次调出了~！
一开始看到这道题
觉得没法搜索啊
如果裸的直接bfs会不会太慢啊
(事实证明虽然没有这种做法快但是也不会T的)
然后就想到要不用SPFA来做？
那怎么表示状态？
到达某个点？
不行啊如果d[u]代表到达u点的状态
那可能有更小的d[u]但是要等待更久
不具有无后效性啊
那定义d[u][t]表示第t时间到达u的最小时间？
哎呀傻逼了窝直接记录周期不就好了吗？
那么很容易有这么一个表示状态的方法
d[u][t]表示在第t个周期到达了u点的最小时间
那么我们很容易证明这个定义是正确可行的
因为这样完整无误地表达了一个状态
并且是具有无后效性和最优子结构的
那么很容易写出这样一个SPFA了
周期的话直接用一个数组nocan[k][u][v]
表示在第k个周期能否从u到v
那么扩展的时候我们对于所有的相邻点
只需要用一个循环来找到最近的周期能到
注意这里如果t加了k次了还不能到v
说明这条路是一直封住的
那么就必要要及时退出(第一次就是忘了break)
然后数据会有k==0的情况
必须要有if(k==0)	k++
不然除数为0就炸了(还好窝机智地猜测到惹23333)
然后这题就水出来了
具体自己看一看叭~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=120;
const int MAXK=15;
const int INF=(1<<30)-1;
struct Edge
{
	int to,next;
}e[MAXN<<4];
int fisrt[MAXN];
struct Node
{
	int poss,time;
};
int d[MAXN][MAXK];
int in[MAXN][MAXK];
bool nocan[MAXK][MAXN][MAXN];
queue<Node> q;
int n,m,k,tot;
int ans=INF;

inline void Add_Edge(int& x,int& y)
{
	e[++tot].to=y;	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Add_Edge(x,y);	Add_Edge(y,x);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		while(scanf("%d%d",&x,&y)==2)
		{
			if(x==0||y==0)
				break;
			nocan[i][x][y]=nocan[i][y][x]=1;
		}
	}
	if(k==0)	
		k++;
	for(int i=1;i<=n;i++)
		for(int j=0;j<k;j++)
			d[i][j]=INF;
}

void SPFA()
{
	d[1][0]=0;	in[1][0]=1;	q.push((Node){1,0});
	Node x;
	while(!q.empty())
	{
		x=q.front();	q.pop();
		int& u=x.poss;	int& time=x.time;	bool flag;
		in[u][time%k]=0;
		for(int i=fisrt[u];i!=-1;i=e[i].next)
		{
			int& v=e[i].to;
			int t=time;	flag=0;
			while(nocan[t%k][u][v])
			{
				t++;
				if(t-time>k+1)
				{
					flag=1;
					break;
				}
			}
			if(flag)
				continue;
			if(t+1<d[v][t%k])
			{
				d[v][t%k]=t+1;
				if(!in[v][t%k])
				{
					in[v][t%k]=1;
					q.push((Node){v,t+1});
				}
			}
		}
		
	}
	for(int i=0;i<k;i++)
		ans=min(ans,d[n][i]);
	if(ans==INF)
		cout<<"No solution."<<endl;
	else
		cout<<ans<<endl;
}

int main()
{
	init();
	SPFA();
	return 0;
}
     