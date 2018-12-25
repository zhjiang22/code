/*
QAQ
好题真心好题
写了一个中午
差点就想放弃了
最后还是写了出来
写了一遍发现第二个样例过不了
整个人都崩溃了
然后试着交了一下结果也有90分
然后就针对第二个样例改了下错就AC了
第一问很好办
直接裸的Tarjan算法标记一下SCC
然后要注意一个单独的点不能算
随便乱搞一下第一问就来了
第二问就直接SCC缩点乱搞了
{
如果某个爱心天使被其他所有人或爱心天使所爱
则请输出这个爱心天使是由哪些人构成的
}
注意这个或和'和'是一个意思(中国文化博大精深)
然后这个地方搞了半天
看了很多别人的写法
感觉都好麻烦啊我们这种弱逼只会自己写简单容易的方法
然后就琢磨了半天
先谢谢这篇博客
http://www.cnblogs.com/yyf0309/p/5677271.html
Orz
{
这题虽然看起来很高大上的样子但是只要想通了就不怎么难了
第一问直接Tarjan不解释。。
第二问嘛。。。首先要把每个强连通分量缩成一个点（理由往下看吧）
所谓的缩点并不是意味着要把图拿来重构，其实用个类似于集合类的思想就
行了，首先将belong数组设成belong[i] = i当i在某个强连通分量中就把belong[i]
设成强连通分量固定的一个值（就是这个强连通分量内的任意一点的belong值，但是
这个强连通分量中的每一个点都要设成一样的）
接着我们画画图：
　　很明显第二问要求的点是强连通分量4，它有什么样的特点呢？
出度为0。如果它的出度不是0会发生什么（其他强连通分量的出度都不为0）？
就会和其他强连通分量形成一个更大的强连通分量，如果存着这个的话，tarjan
算法会先就把它求出来，也就是说这种情况是不可能
　　还有一种情况，就是图不连通：
　　这时候可以发现出度为0的点有两个，但是我们该输出-1
于是我们得到出度为0的点只能有1个，否则输出-1，至于输出
成员嘛。。直接照着belong数组扫一道，就行了
}
我参考了他的思路
但是方法用的更蠢但是更好写的方法
我们要统计出每个天使(SCC)的出度
我就用了个vector scc来保存每个scc中的点
然后对于每个scc中的点的所有邻接点
判断在不在这个scc中
如果不在	说明有一条出边
没有出度的那个强连通分量就是所求的对象
若有多个这样的强连通分量，则说明此图不连通，即输出-1
也可以用Floyd或者并查集做
感觉我这个方法时间复杂度爆表啊
然而数据太水了
竟然还是0ms过了QAQ
Orz
加油	Fighting！
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

const int MAXN=1005;
struct node
{
	int index,low;
	node(int index=-1,int low=-1):index(index),low(low){}
}a[MAXN];
vector<int> g[MAXN];
int n,m;
int SD;
int clock_time;
int in[MAXN];
int out[MAXN];
int sd[MAXN];
int tot[MAXN];
bool v[MAXN];
int ans;
stack<int> s;

void inline Add_Edge(int u,int v)
{
	g[u].push_back(v);
}

void init()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		Add_Edge(x,y);
	}
}

void dfs(int x)
{
	a[x].index=a[x].low=++clock_time;
	s.push(x);
	v[x]=1;
	int d=g[x].size();
	for(int i=0;i<d;i++)
	{
		int y=g[x][i];
		if(a[y].index==-1)
		{
			dfs(y);
			a[x].low=min(a[x].low,a[y].low);
		}
		else	if(v[y])
			a[x].low=min(a[x].low,a[y].index);
	}
	if(a[x].low==a[x].index)
	{
		int k;
		SD++;
		do
		{
			k=s.top();
			s.pop();
			sd[k]=SD;
			v[k]=0;
			tot[SD]++;
		}
		while(k!=x);
	}
}

void Tarjan()
{
	for(int i=1;i<=n;i++)
		if(a[i].index==-1)
			dfs(i);
}

void solve()
{
	int t=0;
	for(int i=1;i<=SD;i++)
		if(tot[i]!=1)
			ans++;
	cout<<ans<<endl;
	vector<int>scc[SD+2];
	for(int i=1;i<=n;i++)
		scc[sd[i]].push_back(i);
	for(int i=1;i<=SD;i++)
	{
		for(int j=0;j<scc[i].size();j++)
			{
				int x=scc[i][j];
				for(int k=0;k<g[x].size();k++)
				{
					 vector<int>::iterator result=find(scc[i].begin( ),scc[i].end( ),g[x][k]); 
					 if(result==scc[i].end())
					 	out[i]++;
				}
			}
	}
	for(int i=1;i<=SD;i++)
		if(out[i]==0&&scc[i].size()!=1)
			t++;
	if(t==1)
	{
		for(int k=1;k<=SD;k++)
			if(out[k]==0)
				for(int i=0;i<scc[k].size();i++)
					cout<<scc[k][i]<<" ";
	}
	else
		cout<<-1<<endl;
}

int main()
{
	init();
	Tarjan();
	solve();
	return 0;
}
     