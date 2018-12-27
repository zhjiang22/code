/*
SPFA可做，考虑到n有十万之大，必定只能用邻接表而非邻接矩阵
首先在读入时建图并存一张反图(即如果存在a到b的边则反图存在b到a的边)
然后我们利用反图从n点开始dfs，使能到达的地方都标记一下
则标记过的地方都是可以在原图中到达n的点
然后我们设dist[i]表示到达i点前可买到的水晶的最小价格
然后用SPFA跑一遍，求出每个点的dist[]值
然后再一个循环查找所有可到达n点的点的v[i]-dist[i]
维护一个最大值ans即可
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int INF=0x7ffffff;
const int MAXN=100005;
vector<int> g[MAXN];
vector<int> g1[MAXN];
queue<int> q;
int v[MAXN];
int dist[MAXN];
bool inq[MAXN];
bool can[MAXN];
int n,m;
int ans=0;

void add(int a,int b)
{
	g[a].push_back(b);
	g1[b].push_back(a);
}

void dfs(int x)
{
	if(can[x])
		return;
	else 
		can[x]=1;
	for(int i=0;i<g1[x].size();i++)
		dfs(g1[x][i]);
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if(z==1)
			add(x,y);
		else
		    add(x,y),add(y,x);
	}
	dfs(n);
	for(int i=1;i<=n;i++)
		dist[i]=INF;
	q.push(1);	inq[1]=true;	dist[1]=v[1];
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=0;i<g[x].size();i++)
		{
			y=g[x][i];
			if(dist[x]<dist[y]||v[y]<dist[y])
			{
				dist[y]=min(dist[y],dist[x]);
				dist[y]=min(dist[y],v[y]);
				if(!inq[y])
					 q.push(y),inq[y]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(can[i])
			ans=max(ans,v[i]-dist[i]);
	cout<<ans<<endl;
	return 0;
}
