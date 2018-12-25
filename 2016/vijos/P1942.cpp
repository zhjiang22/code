/*
好题~深入透彻地进一步了解了bellman-ford算法~
这道题最朴素的做法就是对于加入的边直接加入团
然后再直接Dijkstra然后计算单源最短路~
但是还是比较麻烦的
其实有更好更巧妙的做法
窝们来想一下bellman-ford的算法过程
窝们都是用一条边<u,v>来松弛距离~
所以这里也可以尝试套用这种思想
因为n很小也就100
直接开个邻接矩阵记录距离初始化INF
然后对于次查询s t直接对应查询d[s][t]即可
然后如果有加入边
那么我们用O(n^2)的时间
枚举所有的一对点的距离尝试能不能用这条边<u,v>来松弛他们的距离
d[i][j]=min(d[i][j],d[i][x]+w+d[y][j])
d[i][j]=min(d[i][j],d[i][y]+w+d[x][j])
注意这里的松弛是要两端的
因为两端都有可能被用来松弛~
这样程序就非常好写了
复杂度也是O(n^2*m)
主要是编程复杂度非常低~
很巧妙啦~~~速度也比直接裸的Dijkstra速度快了一倍~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int MAXM=1005;
const int INF=(1<<28)-1;
int d[MAXN][MAXN];
int n,m,tot;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				d[i][j]=INF;
}

void relax(int x,int y,int w)
{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][x]+w+d[y][j]),
				d[i][j]=min(d[i][j],d[i][y]+w+d[x][j]);
}

void work()
{
	int k,x,y,w;
	for(int i=1;i<=m;i++)
	{
		cin>>k;
		if(k==0)
		{
			cin>>x>>y;
			if(d[x][y]==INF)
				cout<<-1<<endl;
			else
				cout<<d[x][y]<<endl;
		}
		else
		{
			cin>>x>>y>>w;
			relax(x,y,w);
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}
     