/*
好题啊	又是一道很典型的划分型(或者说像背包型？)dp
我们知道到了每一圈都有换轮胎或者不换轮胎两种选择
很容易想到定义f[i][j]表示到第i圈，跑完此圈用的是j轮子的最小时间
蠢纸一样的窝一开始很自然地想到了这样的转移方程
即注释里面的那种O(n^3)的转移
即对于当前f[i][j]去找到一个最小的上一圈有可能的轮胎情况
然后直接转移过来
这样的代价很明显三重循环对于1000的数据范围是承受不起的
然后TLE了第一个点
这就非常悲伤了
然后想了半天
终于发现自己脑子抽风了
就是我们的内层K循环	寻找一个最小的f[i-1][]转移过来
而从x轮胎换到y轮胎和从x轮胎换到到z轮胎是等效的(花费的时间都是c)
那么其实我们这个k循环找了k次
每次找到的有用的东西其实都是一个啊~
就是找到的最小的那个值是同一个(就是最有可能更新状态的那个值)
所以这明显是重复了
完全可以对于每一个i直接O(n)的时间找到最小的f[i-1][]
然后用一个变量在循环内记下来(就是我们的minv)
因为我们知道如果f[i-1][k]是最小值
我们用f[i-1][l]去通过换轮胎转移过来
肯定没有f[i-1][k]换轮胎转移过来更优
这是很明显的
找到了这个minv之后
我们就可以尝试换不换轮胎了
如果换轮胎就是minv+c+a[i][j]
如果不换轮胎就是直接f[i-1][j]+a[i][j]就可以了
时间复杂度就是降到了O(n^2)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
const int INF=(1<<30)-1;
int f[MAXN][MAXN];//f[i][j]表示到第i圈，跑完此圈用的是j轮子的最小时间
int a[MAXN][MAXN];
int ans=INF;
int n,m,c;

void init()
{
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=INF;
	for(int i=1;i<=m;i++)
		f[1][i]=a[1][i];
}

int main()
{
	init();
	/*
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				if(j!=k)
					f[i][j]=min(f[i][j],f[i-1][k]+a[i][j]+c);
				else
					f[i][j]=min(f[i][j],f[i-1][k]+a[i][j]);
	*/
	for(int i=2;i<=n;i++)
	{
		int minv=INF;
		for(int j=1;j<=m;j++)
			minv=min(minv,f[i-1][j]);
		for(int j=1;j<=m;j++)
			f[i][j]=min(f[i-1][j],minv+c)+a[i][j];
	}
	for(int i=1;i<=m;i++)
		ans=min(ans,f[n][i]);
	cout<<ans<<endl;
	return 0;
}
     