/*
这道题很明显就是
在一个只有n条有向边的图中，每个结点出度为1，求一个包含节点数最少的环
1.Tarjan算法求所有强连通分量，
然后再求出所有含结点个数不为1的强连通分量的结点个数的最小值
2.先把入度为0的点删除，然后把这个点指向的点的入度-1，
如果入度为0，也删去，这样就只保留有用的点，
那么从任意一个点开始，用vis数组记录是否被访问过，访问到一个新节点就累加计数器，
然后就做出来了.bfs和dfs都可以.
然后可以保证剩下的每个点都在一个有向环中,
同时这个图特殊的建法好像可以保证任意两个环之间没有公共点
3.并查集判断最小环。
输入的每一条信息路径可以看作一条有向边，答案则是所有环中最小环的长度。
用并查集一边合并图，一边检查新增边的两点是否已经在一个root中。
如果为真，则增加此边后就会成环。此时环的大小为dis[x] + dis[y] + 1，
即为所求答案的一个值。
若为假则增加这条边。
维护并查集时引入了一个dis[]数组，记录此节点到根节点的距离（途径边数），
初始化都为0（自己到自己，不存在边）。
若根节点被并入成为另一个子图的儿子，它的子节点的dis在Find的时候被更新。
若成功新并入一条边，新边出发点的dis在Union的时候被更新。
/*
/*
做法1：Tarjan算法
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

const int Maxn =200005;
struct node
{
	int low,index;
	node(int low=-1,int index=-1):low(low),index(index){}
}a[Maxn];
int v[Maxn];
int n;
int Next[Maxn];
int sccnum[Maxn];
int cnt,ans=0x7ffff;
int scc_cnt;
stack<int> s;

void Tarjan(int x)
{
	a[x].index=a[x].low=++cnt;
	s.push(x);
	v[x]=1;
	if(v[Next[x]])
		a[x].low=min(a[x].low,a[Next[x]].index);
	else	if(!sccnum[Next[x]])
	{
		Tarjan(Next[x]);
		a[x].low=min(a[x].low,a[Next[x]].low);
	}
	if(a[x].low==a[x].index)
	{
		int l,tot=0;
		scc_cnt++;
		do
		{
			sccnum[l]=scc_cnt;
			l=s.top();
			tot++;
			s.pop();
		}
		while(l!=x);
		if(tot<=1)	return;
		else ans=min(tot,ans);
	}
}

int main()
{ 
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>Next[i];
	for(int i=1;i<=n;i++)
		if(!v[i])
			Tarjan(i);
	cout<<ans<<endl;
}
*/  
/*
删掉入度为0的点直接dfs求连通块
注意为了方便这里并没有直接删除结点而是将v[x]标记为1
就可以区分开来
*/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int Maxn=200010;
int ans=0x7fffff;
int n;
int to[Maxn];
bool v[Maxn];
int in[Maxn];

void topo(int x)
{
	in[to[x]]--;//邻接点入度-1
	v[x]=1;
	if(!in[to[x]])
		topo(to[x]);
}

void dfs(int x,int tot)
{
	v[x]=1;
	if(!v[to[x]])
		dfs(to[x],tot+1);
	else	if(tot!=1)
		ans=min(ans,tot);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>to[i];
		in[to[i]]++;
	}
	for(int i=1;i<=n;i++)
		if(!in[i]&&!v[i])
			topo(i);
	for(int i=1;i<=n;i++)
		if(!v[i])
			dfs(i,1);
	cout<<ans<<endl;
	return 0;
}
*/
/*
并查集做法,具体见代码咯，因为是按照边合并的所以肯定不会有独立点的情况
就可以不用特判独立点咯
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int Maxn=200005;
int f[Maxn];
int dis[Maxn];//初始化0
int n;
int ans=0x7fffff;

void init()
{
	for(int i=1;i<=n;i++)
		f[i]=i;
}

int getfather(int x)
{
	if(x==f[x])
		return x;
	int root=f[x];
	f[x]=getfather(f[x]);//这句话要在前面不然WA(先压缩路径？)
	dis[x]+=dis[root];//更改dis路径长度
	return f[x];
}

void Union(int x,int y)
{
	int x1=getfather(x);
	int y1=getfather(y);
	if(x1!=y1)
	{
		f[x1]=y1;//合并集合
		dis[x]=dis[y]+1;//更改长度
	}
	else//找到环了
		ans=min(ans,dis[x]+dis[y]+1);//距离为dis[x]+dis[y]+1
}

int main()
{
	cin>>n;
	init();
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		Union(i,x);//合并
	}
	cout<<ans<<endl;
	return 0;
}

