/*
SCC缩点题~好题~
竟然一遍AC了(好吧其实是第一次交忘记删除某个调试语句然后WA了一次.....)
OTZ
其实思路很简单啦~
看到题目的意思就知道很明显的强连通分量模型~
窝们首先用个Tarjan算法求出SCC然后用sccno[]标记一下每个点的强连通分量编号
就相当于将所有的强连通分量缩成了一个点~
那么第一问的答案是什么呢？
第一眼看过去觉得就是个裸的求SCC个数？
不对	是求入度为0的SCC个数~
因为如果一个SCC设为x中某个结点连着一条有向边到另一个SCCy中
那么如果x中有了一个软件
那么整个x中有了一个软件
自然也会传递到y中去
那么整个y中也会有软件
那么问题就很明显是要求有多少个入度为0的SCC
如果入度为0自然是要单独给个软件了
怎么判断SCC是否入度为0呢
我们用一个in[],out[]记录每个SCC的入度和出度
那么枚举所有点以及它们的相邻点
如果两个点不在同一个SCC中那么自然他们对应的SCC就是有了入度和出度
处理好了这个问题我们来看看第二问
第二问要求最多加入多少条边
能让整个图强连通的
注意第二问要特判一下SCC数为1即只有一个强连通分量时为0
其实这个可以在找出SCC后直接特判也可以提高效率~
即如果发现scc_cnt为1那么直接输出1 0就好了~
如果SCC数不为1
证明如下:
{
对于多个连通快
设每个连通块入度为0的点只有1个
设每个连通块出度为0的点为k个
设k>1
则k-1个点连向自己连通快入度为0的点
剩下一个点连到其他连通块的入度为0的点
其他情况类似，不一一列举.所以当点>1时，答案为max(x,y)
}
说通俗的
因为加的边总是加：起点为出度为0的，终点为入度为0的
然后如果a>b，那么剩下的a-b条边就乱加……b>a也是同样的……
所以就可以得到这个结论~
那么很容易发现其实就是max(入度为0的SCC数,出度为0的SCC数)
就可以很轻松地做出来了
窝用的邻接表写哒~可以直接秒杀~！
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

const int MAXN=105;
const int MAXM=10005;
const int INF=(1<<30)-1;
struct Edge
{
	int to,next;
}e[MAXM];
int pre[MAXN],low[MAXN];
int in[MAXN],out[MAXN];
int first[MAXN];
int sccno[MAXN];
int scc_cnt,clock_time;
int n,m,tot;
stack<int> s;

inline void Add_Edge(int x,int y)
{
	tot++;	e[tot].to=y;	e[tot].next=first[x];	first[x]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
	int v;
	cin>>n;
	for(int i=1;i<=n;i++)
		while(cin>>v)
		{
			if(v==0)
				break;
			Add_Edge(i,v);
		}
}

void dfs(int u)
{
	pre[u]=low[u]=++clock_time;
	s.push(u);
	for(int i=first[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(!pre[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else	if(!sccno[v])
			low[u]=min(low[u],pre[v]);
	}
	if(pre[u]==low[u])
	{
		scc_cnt++;
		int x;
		while(x!=u)
		{
			x=s.top();	s.pop();
			sccno[x]=scc_cnt;
		}
	}
}

void Tarjan()
{
	for(int i=1;i<=n;i++)
		if(!pre[i])
			dfs(i);
	if(scc_cnt==1)
	{
		cout<<1<<endl<<0<<endl;
		exit(0);
	}
}

void getans()
{
	for(int u=1;u<=n;u++)
	{
		for(int i=first[u];i!=-1;i=e[i].next)
		{
			int v=e[i].to;
			if(sccno[u]!=sccno[v])
			{
				in[sccno[v]]++;
				out[sccno[u]]++;
			}
		}
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=scc_cnt;i++)
	{
		if(!in[i])
			ans1++;
		if(!out[i])
			ans2++;
	}
	cout<<ans1<<endl;
	cout<<max(ans1,ans2)<<endl;
}

int main()
{
	init();
	Tarjan();
	getans();
	return 0;
}
     