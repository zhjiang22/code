/*
好题啊~唯一的坑点在于
想到了答案会在Longlong类型内	但是没想到
输入的数据也要开longlong
害怕啊然后一直WA一半的点然而却找不出错来
首先窝们玩过游戏的都知道
如果有减速,持续伤害,一次伤害的
那么肯定把一次伤害的放在最后面最优
因为这样能让持续性的伤害最大化
那么我们定义f[i][j]表示放i个蓝j个绿的最大伤害
这里的伤害不算上红色的伤害
那么自然很明显有初值
d[0, 0]:=0; {没有法师}
d[0, 1]:=0; {只放一个绿法师}
d[0, j]:=d[0, j-1]+(j-1)*g*t;(1<=j<=n)
{不放蓝法师，在前j个位置放绿法师的(最大)伤害}
d[i, 0]:=0;(1<=i<=n) {不放绿法师，在前i个位置放置蓝法师，伤害均为零}
那么状态转移方程也很容易出来
f[i][j]=max(f[i-1][j]+((i-1)*b+t)*g*j,f[i][j-1]+(i*b+t)*g*(j-1));
最后寻找答案的时候
应该枚举所有的f[i][j]然后剩下的就是放红色的法师了
计算出最大值就好了~
即max(ans,f[i][j]+(n-i-j)*(r+g*j)*(t+b*i))
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1028;
long long f[MAXN][MAXN];//f[i][j]表示放i个蓝j个绿的最大伤害
long long n,r,g,b,t;
long long ans=-1;

void init(){cin>>n>>r>>g>>b>>t;}

int main()
{
	init();
	for(int j=2;j<=n;j++)
		f[0][j]=f[0][j-1]+(j-1)*g*t;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n-i;j++)
		{
			if(j>0)
				f[i][j]=max(f[i-1][j]+((i-1)*b+t)*g*j,f[i][j-1]+(i*b+t)*g*(j-1));
			else
				f[i][j]=f[i-1][j]+((i-1)*b+t)*g*j;
			ans=max(ans,f[i][j]+(n-i-j)*(r+g*j)*(t+b*i));
		}
	cout<<ans<<endl;
	return 0;
}
     