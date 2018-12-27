/*
好题啊~建模很精妙的说~~
一开始看到觉得是并查集的说~
但是好像真的不太好写~(窝太弱惹)
看到题解区里有说并查集可做哒~
{这就是个并查集的题,有个添加关系的顺序,问你添加到第几个关系的时候出现了矛盾.
然后输出一大堆The Graph has Fat Tour.,再输出一大堆Poor Fat Tour.}
出题人的标解应该就是二分图吧
很奇妙哒~
这道题是要窝们求存不存在一个奇数顶点个数的环
想到了什么？
二分图~！首先二分图有环的话必然是偶数环
同时在二分图染色判定时
如果发现存在染色冲突	那么必然是发现了奇数点的偶数环~！
那么我们完全可以将这个性质反过来用
我们可以用二分图染色来判定是否存在奇数环！
那么就可以直接dfs或者bfs染色	如果有冲突(返回false)说明存在小胖回路
那么我们就可以很自然地解决这道题了
即用邻接矩阵建图	删除一个点就是将所有关于这个点的边去掉
然后每次进行一次dfs染色就好啦~
n就800也不必害怕爆栈直接dfs就好啦	时间也是蛮快的~
果然图论的最难点就是建模惹~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=805;
int g[MAXN][MAXN];
int color[MAXN];
int n,m,p;

void init()
{
	int x,y;
	cin>>n>>m>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		g[x][y]=g[y][x]=1;
	}
}

bool dfs(int u,int clo)
{
	color[u]=clo;
	for(int i=1;i<=n;i++)
		if(g[u][i])
		{
			if(color[i]==color[u])
				return false;
			if(!color[i]&&!dfs(i,3-clo))
				return false;
		}
	return true;
}

int main()
{
	init();
	int x;
	for(int k=1;k<=p;k++)
	{
		cin>>x;	bool ok=0;
		for(int i=1;i<=n;i++)
			g[x][i]=g[i][x]=0;
		memset(color,0,sizeof(color));
		for(int i=1;i<=n;i++)
			if(!color[i]&&!dfs(i,1))
			{
				ok=1;	break;
			}
		if(ok)
			printf("The Graph has Fat Tour.\n"); 
		else
			printf("Poor Fat Tour.\n");  
	}
	return 0;
}
     