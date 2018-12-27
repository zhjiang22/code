/*
对于此题而言，floyd可以做，但不是最优选择。如果把数据加强到n=1000，
则应该使用两次Dijkstra（正向反向各一次），然后枚举中间点来选取答案。
这样做的时间复杂度为O(V2)O(V2)，对于n=1000绰绰有余。

Floyd做法：a[i]表示第i个弯道时间，d[i][j]表示第i个弯道到第j个弯道时间，初始化INF
接着运用floyd求出各个弯道之间直道最短时间，记得要加上连接弯道的直道时间。
题目要求要经过1弯道的最短路且必要有一直道路，说明必要有两个弯道连接而成加上直道，
则枚举2到n所有点，取其d[1][i]+a[i]+d[i][1]+a[1]最小值。
还需要判断是否存在解即判断与INF的关系。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF=0x7ffffff;
int d[202][202];
int a[202];
int n,m;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)	d[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		int x,y,v;
		cin>>x>>y>>v;
		d[x][y]=min(d[x][y],v);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+a[k]+d[k][j]);
	int ans=INF;
	for(int i=2;i<=n;i++)
		ans=min(ans,d[1][i]+a[i]+d[i][1]+a[1]);
	if(ans==INF)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
     