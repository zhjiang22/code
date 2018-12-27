/*
水题啊纯粹
一开始差点还被题目给骗了
以为是一道难题
结果仔细一想	啥题目啊
Orz
先读入图(数据这么小直接邻接矩阵啊)
然后Floyd处理一下最短路
然后再来一遍Floyd(类似但不能算Floyd)
枚举这个加油点k
然后一直取最大值就好
然后输入一个询问判断一下是不是无法到达(INF)
是的话-1
不是输出f[x][y]
水题QWQ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=305;
const int INF=(1<<30)-1;
int f[MAXN][MAXN];
int d[MAXN][MAXN];
int v[MAXN];
int n,m,q;

void init()
{
	int x,y,w;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=d[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		d[x][y]=d[y][x]=min(d[x][y],w);
	}
	for(int i=1;i<=n;i++)
		d[i][i]=0;
}

void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],d[i][k]+d[k][j]+v[k]);
}

void solve()
{
	int x,y;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(f[x][y]==INF)
			cout<<-1<<endl;
		else
			cout<<f[x][y]<<endl;
	}
}

int main()
{
	init();
	Floyd();
	solve();
	return 0;
}
     