/*
一个挺简单的区间DP叭
今天很不在状态的感觉弄了半天
我们定义f[i]表示到第i辆车
所需要的最大时间
那么初值必然是
f[0]=0	f[1]=L/v[1]了
考虑怎么转移状态
我们来看决策有多少种
我们可以知道	每一个车
肯定是接在前面某个k辆车后面(即前面某个组后面)
要么自成一组
诶这不是和很多区间dp一样么？
都是套路呀就像是寻找一个断点一样寻找一个接点
这么看来就很简单了
我们有状态转移方程
f[i]=min(f[i],f[j]+t(j,i))	(0<j<=i并且sum[j][i]<=M)
其中t(j,i)表示从j到i为一组过桥所需要的时间了
然后我们很容易想到预处理每个区间速度的最小值
以及每个区间内的总重量
那么我们看到这里有一个小小的技巧了
我们知道sum[j][i]随着j的减小一定是单调递增的
所以如果我们发现到了某一个j满足sum[j][i]>M了
那么继续减小j也一定会大于M了
就没有必要继续减小了直接剪掉
这样其实会减小好多复杂度的在实际应用中
所以这就是一道区间DP裸题
时间复杂度O(n^2)	乱搞就好了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
double f[MAXN];
double w[MAXN];
double v[MAXN];
double s[MAXN][MAXN],minv[MAXN][MAXN];
double L,M;
int n;

void init()
{
	cin>>M>>L>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if(i==j)
				s[i][j]=w[i],minv[i][j]=v[i];
			else
				s[i][j]=s[i][j-1]+w[j],minv[i][j]=min(minv[i][j-1],v[j]);
		}
	f[0]=0;
	f[1]=L/v[1];
}

int main()
{
	init();
	for(int i=2;i<=n;i++)
	{
		f[i]=999999;
		for(int j=i-1;j>=0;j--)
		{
			if(s[j+1][i]>M)
				break;
			else
				f[i]=min(f[i],f[j]+(double)(L/minv[j+1][i]));
		}	
	}
	printf("%.1lf\n",f[n]*60);
	return 0;
}
     