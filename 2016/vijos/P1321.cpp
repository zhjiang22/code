/*
好题
一个带上了限制条件的路径问题
大概说一下题目意思吧
就是i号房间中有i号武器
而每条无向边有一个限制就是必须有i号武器才能通过
我是用dfs做的
显然，一个房间在一个时刻能抵达，那么以后也可以，这点很重要
所以我们其实可以简化下思路
我们这样想
一个房间能被访问的条件是：
1有相邻房间被访问 
2相邻房间连着的道路可以通过 
这两个条件缺一不可对吧
而我们其实可以这样想，我们每次把能走的房间先走一下
我们每访问一个房间i，都能使得一些新房间的条件得到满足，这些新房间就可能可以被访问
然后就一直这样"模拟走房间走下去"知道不能再走为止
这就转换为一个dfs模型了
因此，我们在访问完房间i后
将i连向的房间检查一次能否访问(尝试更新别的房间条件1)
将怪物i守住的道路检查一次能否访问(尝试更新别的房间的条件2)
这样就能保证每条路和每个节点都只被访问一次了 
时间复杂度O(n+m)
而这里我们很明显
不但要储存边和其怪物种类	还需要记录一下某种武器能更新的边
这个其实同用一个结构体就可以完成(偷懒啊)(所以导致我的代码有点丑Orz非常丑)
然后我们就可以开始dfs
对于当前的点x
我们检查一下x房间中的x武器可以走过的边
如果有这样一条权值x(需要x武器)无向边	他的一个端点还是不能到达但是另一个端点可以到达
那么我们到达了x房间后	我们实际上是可以拿着这个武器走到那里走通那个点的
所以那个无法到达的点就被更新为到达的点了
而有一个点能到达了
我们考虑一下可能原来这个新能到达的点
有一条边(已经有了这条边的武器)连着另一个还未到达的店
那我们就可以沿着这条边一走又有一个点可以到达了
实际上我们就是抓住这两个条件
相邻点和道路通
然后不断dfs直到不能走位置
Orz就做出来了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=50005;
struct Edge
{
	int to,nxt,w;
	Edge()
	{
		to=nxt=w=-1;
	}
}e[MAXN*2],ec[MAXN];
int first[MAXN];
int fc[MAXN];
int v[MAXN];
int n,m,s;
int tot,totc;

void Add_Edge(int x,int y,int c)
{
	tot++;
	e[tot].to=y;
	e[tot].w=c;
	e[tot].nxt=first[x];
	first[x]=tot;
}

void Add_c(int c,int x,int y)
{
	totc++;
	ec[totc].to=x;
	ec[totc].w=y;
	ec[totc].nxt=fc[c];
	fc[c]=totc;
}

void init()
{
	memset(first,-1,sizeof(first));
	memset(fc,-1,sizeof(fc));
	int x,y,c;
	cin>>n>>s>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		Add_Edge(x,y,c);
		Add_Edge(y,x,c);
		Add_c(c,x,y);
	}
}

void dfs(int x)
{
	v[x]=1;
	for(int i=fc[x];i!=-1;i=ec[i].nxt)
	{
		int from=ec[i].to;	int to=ec[i].w;
		if(v[from]&&(!v[to]))
			dfs(to);
		else	if(v[to]&&(!v[from]))
			dfs(from); 
	}
	for(int i=first[x];i!=-1;i=e[i].nxt)
	{
		int from=e[i].to;	int to=e[i].w;
		if(v[to]&&(!v[from]))
			dfs(from);
	}
}

void out()
{
	for(int i=1;i<=n;i++)
	{
		cout<<i<<":";
		if(v[i])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}

int main()
{
	init();
	dfs(s);
	out();
	return 0;
}
     