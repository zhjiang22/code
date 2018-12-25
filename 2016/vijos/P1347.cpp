/*
一道经典的区间动态规划了
和某年的那个能量项链不谋而合的感觉
然后就随手A了
我们定义一个状态f[i][j]表示前i个数字加入j个括号所能获得的最大值
因为我们是加入括号直接获得数字串乘积的
所以我们肯定要先预处理一下这个数字的值？
用num[i][j]表示第i到j位的数字的值
然后我们很明显就根据套路来
状态转移方程有
f[i][j]=max(f[i][j],f[k][j-1]*num[k+1][i]);
其中k是枚举的断点
初值就直接f[i][0]=num[1][i]
然后就一个三重循环递推就好了
时间复杂度O(n^3)
对于我们的n=40绰绰有余了
这个数据范围太小了
其实记忆化或者dfs加上点剪枝
也能过的
OTZ窝好弱啊
只会水题
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=45;
int f[MAXN][8];
int num[MAXN][MAXN];
int a[MAXN];
int n,K;

void getnum()
{
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int t=a[i];
			for(int K=i+1;K<=j;K++)
				t=(t*10)+a[K];
			num[i][j]=t;
		}
}

void init()
{
	cin>>n>>K;
	for(int i=1;i<=n;i++)
		scanf("%01d",&a[i]);
	getnum();
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		f[i][0]=num[1][i];
	for(int i=2;i<=n;i++)
		for(int j=1;j<=min(i-1,K);j++)
			for(int k=j;k<i;k++)
					f[i][j]=max(f[i][j],f[k][j-1]*num[k+1][i]);
	cout<<f[n][K]<<endl;
	return 0;
}
     