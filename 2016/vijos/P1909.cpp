/*
NOIP2014的day2T2
本来以为很难的样子我应该只能打暴力了
但是事实证明NOIP2014真心很水
这是我第一次
没有制作任何样例(没带笔233333)
然后就直接一次AC了
Orz第一次感到膜拜我自己
哎但我还是好弱啊	不知道我这种做法强不强
然后做完后看了下题解	好像很多和我思路一样的
首先因为要判断能否到达终点
所以这一步要预先处理好(感觉和我做的NOIP最优贸易这一步是一样的)
先建立个邻接向量的同时建个反图	然后从终点开始dfs
can[]标记所有能到达终点的点
Orz这一个就处理好了
(用别的方法建立判断也可以 但是NOIP内存一直很多	所以就用反图方便咯)
然后跑一边SPFA
就是加了一个判断条件
对于每个点不仅它自己要能到达终点它的所有相邻点也必须要能到达相邻点
所以就加个在尝试更新的时候先check一下
然后就直接还要注意判断一下能否到达终点咯	不能就直接-1
然后就直接做完了
总体不难吧	主要看心态了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=10005;
const int INF=9999999;
vector<int> g[MAXN];
vector<int> g1[MAXN];
int can[MAXN];
int n,m;
int s,t;
queue<int> q;
bool in[MAXN];
int d[MAXN];

void Add_Edge(int x,int y)
{
	g[x].push_back(y);
	g1[y].push_back(x);
}

void init()
{
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		Add_Edge(x,y);
	}
	cin>>s>>t;
}

void dfs(int x)
{
	if(can[x])
		return;
	if(!can[x])
		can[x]=1;
	for(int i=0;i<g1[x].size();i++)
		dfs(g1[x][i]);
}

bool check(int x)
{
	if(!can[x])
		return false;
	for(int i=0;i<g[x].size();i++)
	{
		if(!can[g[x][i]])
			return false;
	}	
	return true;
}

void SPFA(int s)
{
	for(int i=1;i<=n;i++)
		d[i]=INF;
	d[s]=0;
	q.push(s);
	in[s]=1;

	while(!q.empty())
	{
		int x=q.front();
		q.pop();

		for(int i=0;i<g[x].size();i++)
		{
			if(check(g[x][i]))
				if(d[g[x][i]]>d[x]+1)
				{
					d[g[x][i]]=d[x]+1;
					if(!in[g[x][i]])
						in[g[x][i]]=1,q.push(g[x][i]);
				}
		}
	}
	if(d[t]==INF)
		cout<<-1<<endl;
	else
		cout<<d[t]<<endl;
}

int main()
{
	init();
	dfs(t);
	SPFA(s);
	return 0;
}
     