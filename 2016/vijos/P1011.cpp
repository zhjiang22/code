/*
一道动态规划题(记忆化搜索做)
我们发现可以完整表示一个状态的需求只要有(x,y)就可以了
即起点(x,y)固定
那么从这个点出发能滑到的最长长度就是确定了的~
很容易发现这里是有很多重叠子问题的~
同时具有最优子结构和无后效性
所以我们可以用用f[x][y]表示在(x,y)所能到达的最长长度
那么我们用个记忆化搜索搜一下
高度数组可以预设无穷大表示不能走~
这样就可以不用判断边界了因为一定不会走到了
当然也可以扩展的时候特判一下边界
最后找到f[][]的最大值即可
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=505;
int h[MAXN][MAXN];
int f[MAXN][MAXN];
int n,m;
int ans;
int zx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void init()
{
	memset(h,0x3f,sizeof(h));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&h[i][j]);
}

int dfs(int x,int y)
{
	if(f[x][y])
		return f[x][y];
	int res=1;
	for(int i=0;i<4;i++)
	{
		int newx=x+zx[i][0];	int newy=y+zx[i][1];
		if(h[x][y]>h[newx][newy])
			res=max(res,dfs(newx,newy)+1);
	}
	return f[x][y]=res;
}

void DP()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!f[i][j])
				dfs(i,j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=max(ans,f[i][j]);
	cout<<ans<<endl;
}

int main()
{
	init();
	DP();
}
     
     