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

const double INF=666666.0;
struct node
{
	double x,y;
}a[203];
double dist[203];
double d[203];
double map[203][203];
int fa[203];
bool in[203];
int n,m;
double min1,min2;
queue<int> q;

double turn(int x,int y)
{
	double dx=a[x].x-a[y].x;
	double dy=a[x].y-a[y].y;
	double r=dx*dx+dy*dy;
	return sqrt(r);
}

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			map[i][j]=INF;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		map[x][y]=map[y][x]=turn(x,y);
	}

}

void SPFA(int s)
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=0;
		dist[i]=INF;
		in[i]=false;
	}
	while(!q.empty())
		q.pop();
	q.push(s);
	in[s]=true;
	dist[s]=0;

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
}

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
	init();
	//先求出最短路，fa[]记录
	SPFA(1);
	min1=dist[n];
	int now=n;
	int p1,p2;
	min2=INF;
	while(fa[now])
	{
		//沿着最短路一路返回
		p1=now;
		p2=fa[now];
		now=fa[now];
		//记录下值以便还原边
		double t=map[p1][p2];
		//删除边
		map[p1][p2]=map[p2][p1]=INF;
		//求删边后的最短路
		spfa(1);
		//记录删边后的所有路最短路中的最小距离值
		min2=min(min2,d[n]);
		//还原边
		map[p1][p2]=map[p2][p1]=t;
	}
	if(min2==INF)
		cout<<-1<<endl;
	else 
		printf("%.2lf\n",min2);
	return 0;
}
     