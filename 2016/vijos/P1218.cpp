/*
一个蛮简单的DP吧
然而却弄了我一晚上
发现我真是不会DP的弱逼啊
%%%%%%%%各位dp大神教我dfs吧
哎我们来看因为这是一个环的问题
很明显环形dp最简单可行的方法就是我们直接把他拉成一条链
长度*2然后固定长度枚举起点即可
然后对于每次枚举的起点的结果可能达到的最大值DP一下
对于这些比较一下取最值就好了
本来是写一个DP就好了	但是我就是傻就喜欢写两个dp
每次sum要重新计算
来看看我们的动规部分
f[i][j]表示前i个数分成j部分的最优值
状态转移方程：
f[i][j]=opt(f[i][j],f[k][j-1]*(((sum[i]-sum[k])%10+10)%10))
sum[i]是前i个数的和
边界：
f[0][0]=1;
f[i][1]=((sum[i]%10+10)%10)
这样我们随便推一推就好了OTZ
真的好弱啊考试就准备直接dfs了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int a[MAXN];
int f[MAXN][MAXN];//f[i][j]前i个数分成j份
int sum[MAXN];
int n,m;
int ans=999999;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i+n]=a[i];
}

int getmin(int a[])
{
	for(int i=1;i<=n;i++)  
        sum[i]=sum[i-1]+a[i]; 
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][1]=(sum[i]%10+10)%10;
	f[0][0]=1;
	for(int j=2;j<=m;j++)
		for(int i=j;i<=n;i++)
		{
			for(int k=j-1;k<i;k++)
				f[i][j]=min(f[i][j],f[k][j-1]*(((sum[i]-sum[k])%10+10)%10));
		}
	return f[n][m];
}

int getmax(int a[])
{
	for(int i=1;i<=n;i++)  
        sum[i]=sum[i-1]+a[i]; 
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][1]=(sum[i]%10+10)%10;
	f[0][0]=1;
	for(int j=2;j<=m;j++)
		for(int i=j;i<=n;i++)
		{
			for(int k=j-1;k<i;k++)
				f[i][j]=max(f[i][j],f[k][j-1]*(((sum[i]-sum[k])%10+10)%10));
		}
	return f[n][m];
}

int main()
{
	init();
	for(int i=0;i<n;i++)
		ans=min(ans,getmin(a+i));
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
		ans=max(ans,getmax(a+i));
	cout<<ans<<endl;
	return 0;
}
     