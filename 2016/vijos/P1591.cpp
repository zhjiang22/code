/*
NOI竟然有如此水之题Orz
看到n最大100就有了中Floyd的冲动233333~
其实这题目很简单的
最简单的做法是Floyd一遍，如果泥愿意n次spfa dijkstra也都是可以过的
欺负他n小啊
讲讲最好的Floyd做法吧
读入邻接矩阵图后	根据Floyd的DP无后效性
那么我们统计(i,j)之间的最短路径的距离很容易在三重循环中这样统计出
if(g[i][j]==g[i][k]+g[k][j])
	s[i][j]+=s[i][k]*s[k][j];
if(g[i][j]>g[i][k]+g[k][j])
	g[i][j]=g[i][k]+g[k][j]	s[i][j]=s[i][k]*s[k][j];
这个很容易用乘法原理证明正确性咯~
一个简单的Floyd变型呀~
那么输出答案的时候
对于每个点枚举一对点(i,j)
如果有g[i][k]+g[k][j]==g[i][j]
说明他是某条i,j之间上的点
那么经过这个点k的i,j的最短路径数根据乘法原理为
s[i][k]*s[k][j]
然后统计一下就好啦~
注意这个路径数肯定会有很多的
所以s[][]需要开到long long才能AC
统计ans的时候最好是先除后乘防止溢出(这里直接乘也不会爆炸的)
Orz就做完啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int INF=(1<<30)-1;
int g[MAXN][MAXN];
long long s[MAXN][MAXN];
int n,m;

void init()
{
	int x,y,w;
	cin>>n>>m;
	memset(g,0x3f,sizeof(g));
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			s[i][j]=1;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		g[x][y]=g[y][x]=w;
	}
}

void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&k!=i) 
				{
					if(g[i][j]==g[i][k]+g[k][j])
						s[i][j]+=s[i][k]*s[k][j];
					else	if(g[i][j]>g[i][k]+g[k][j])
					{
						g[i][j]=g[i][k]+g[k][j];
						s[i][j]=s[i][k]*s[k][j];
					}
				}
}

void out()
{
	for(int k=1;k<=n;k++)
	{
		double ans=0.0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=k&&j!=k&&i!=j)
					if(g[i][k]+g[k][j]==g[i][j])
						ans+=(double)((double)s[i][k]/s[i][j]*s[k][j]);//先除后乘以防溢出
		printf("%.3f\n",ans);
	}
}

int main()
{
	init();
	Floyd();
	out();
	return 0;
}
     