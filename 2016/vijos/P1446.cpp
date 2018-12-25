/*
看到数据范围n只有100大
那么我们可以直接邻接矩阵存图+Floyd更新最短路
那么怎么判断最短路径上点的个数呢?
其实很简单
如果有i为x,y最短路径上的一个点
那么必然有d[x][y]==d[x][i]+d[i][y]
对于i==x或者i==y也成立
(因为d[x][x]==d[y][y]==0)
所以直接每输入x,y
枚举所有点是否满足上述条件即可
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF=0x7ffff;

int w[102][102];
int n,e;

int main()
{
	cin>>n>>e;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			w[i][j]=INF;
	for(int i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		w[x][y]=w[y][x]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(w[i][k]+w[k][j]<w[i][j])
					w[i][j]=w[i][k]+w[k][j];


	int q;
	cin>>q;
	while(q--)
	{

		int ans=0;
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++)
			if(x!=j&&y!=j)
			if(w[x][y]==w[x][j]+w[j][y])
			ans++;	
		cout<<ans+2<<endl;
	}
	return 0;
}
     