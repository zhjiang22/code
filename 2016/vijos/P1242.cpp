/*
一个不算很难的dp啦~~
有个神犇的题解就直接贴上来了~~
{
题意：用数轴描述一条高速公路，有V个村庄，每一个村庄坐落在数轴的某个点上，需要选择P个村庄在其中建立邮局，要求每个村庄到最近邮局的距离和最小。
分析：典型的DP：
1、考虑在V个村庄中只建立一个邮局的情况，显然可以知道，将邮局建立在中间的那个村庄即可。也就是在a到b间建立
一个邮局，若使消耗最小，则应该将邮局建立在（a+b)/2这个村庄上。
2、下面考虑建立多个邮局的问题，可以这样将该问题拆分为若干子问题，在前i个村庄中建立j个邮局的最短距离，是
在前k个村庄中建立j-1个邮局的最短距离与 在k+1到第i个邮局建立一个邮局的最短距离的和。而建立一个邮局我们在
上面已经求出
3、状态表示，由上面的讨论，可以开两个数组
dp[i][j]:在前i个村庄中建立j个邮局的最小耗费
sum[i][j]:在第i个村庄到第j个村庄中建立1个邮局的最小耗费
那么就有转移方程：dp[i][j] = min(dp[i][j],dp[k][j-1]+sum[k+1][i]) DP的边界状态即为dp[i][1] = sum[1][i];
所要求的结果即为dp[V][P];
4、然后就说说求sum数组的优化问题，可以假定有6个村庄，村庄的坐标已知分别为p1,p2,p3,p4,p5,p6;那么，如果要
求sum[1][4]的话邮局需要建立在2或者3处,放在2处的消耗为p4-p2+p3-p2+p2-p1=p4-p2+p3-p1放在3处的结果为p4-
p3+p3-p2+p3-p1=p4+p3-p2-p1，可见，将邮局建在2处或3处是一样的。现在接着求sum[1][5],现在处于中点的村庄是
3，那么1-4到3的距离和刚才已经求出了，即为sum[1][4],所以只需再加上5到3的距离即可。同样，求sum[1][6]的时候
也可以用sum[1][5]加上6到中点的距离。所以有递推关系：sum[i][j] = sum[i][j-1] + p[j] -p[(i+j)/2]
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=305;
int s[MAXN][MAXN];
int f[MAXN][MAXN];//f[i][j]表示前i个村庄建j个邮局的最小代价
int a[MAXN];
int n,m;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
				s[i][j]=s[i][j-1]+a[j]-a[(i+j)/2];
}

void DP()
{
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][1]=s[1][i];
	for(int j=2;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
			for(int k=1;k<i;k++)
				f[i][j]=min(f[i][j],f[k][j-1]+s[k+1][i]);
	}
	cout<<f[n][m]<<endl;
}

int main()
{
	init();
	DP();
}