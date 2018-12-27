/*
一道挺简单的DP的
主要难点在于怎样设计一个好的可行的状态
状态设计出来了状态转移方程也就很好写了
我们来看看这样的状态设计
f[i][j]表示以a[i]结尾的长度为j的LIS的个数
这样是可行的(还是自己考虑一下叭)
状态转移方程就很好写了
f[i][j]=sum{f[k][j-1]}
其中1<=k<i且i能接在k后面即a[i]>=a[k]
初值为f[i][1]=1
可能是太久没写DP了生疏了
一开始状态转移时j循环竟然写成了从1开始
也是蠢哭啊
答案要开longlong不然WA一个点
OTZ窝好弱啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int MAXM=23;
int a[MAXN];
long long f[MAXN][MAXM];
int n,m;
long long ans;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		f[i][1]=1;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)//从2开始，一开始错在这
			for(int k=1;k<i;k++)
				if(a[i]>=a[k])
					f[i][j]+=f[k][j-1];
	for(int i=1;i<=n;i++)
		ans+=f[i][m];
	cout<<ans<<endl;
	return 0;
}
     