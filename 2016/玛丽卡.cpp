/*
先求一次最短路，记录下路径。
再不断删除一条最短路上的路线，求出此时的距离，取其最小值。
即删边法>3<
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <cmath>
using namespace std;

const int INF=666666;
int dist[1005];
int d[1005];
int map[1005][1005];
int fa[1005];
bool in[1005];
int n,m;
int min1,min2;
queue<int> q;

void spfa(int s)//两次的SPFA不同，即不需要记录最短路径
{
	for(int i=1;i<=n;i++)
		d[i]=INF;
	memset(in,0,sizeof(in));
	q.push(s);
	in[s]=1;
	d[s]=0;

	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		in[x]=0;

		for(int i=1;i<=n;i++)
		{
			if(d[i]>d[x]+map[x][i])
			{
				d[i]=d[x]+map[x][i];
				if(!in[i])
				{
					in[i]=1;
					q.push(i);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int x,y,v;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			map[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>v;
		map[x][y]=v;
		map[y][x]=v;
	}
	//先求出最短路，fa[]记录
	for(int i=1;i<=n+1;i++)
	{
		fa[i]=0;
		dist[i]=INF;
		in[i]=false;
	}
	while(!q.empty())
		q.pop();
	q.push(1);
	in[1]=true;
	dist[1]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		in[x]=false;

		for(int i=1;i<=n;i++)
			if(dist[i]>dist[x]+map[x][i])
			{
				dist[i]=dist[x]+map[x][i];
				fa[i]=x;
				if(!in[i])
				{
					in[i]=1;
					q.push(i);
				}
			}
	}
	min1=dist[n];
	int now=n;
	int p1,p2;
	min2=0;
	while(fa[now])
	{
		//沿着最短路一路返回
		p1=now;
		p2=fa[now];
		now=fa[now];
		//记录下值以便还原边
		int t=map[p1][p2];
		//删除边
		map[p1][p2]=map[p2][p1]=INF;
		//求删边后的最短路
		spfa(1);
		//记录删边后的所有路最短路中的最小距离值
		min2=max(min2,d[n]);
		//还原边
		map[p1][p2]=map[p2][p1]=t;
	}
	cout<<min2<<endl;
	return 0;
}
     