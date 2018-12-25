/*
这道题很明显是动态规划了~
和矩阵连乘问题一个道理呀只不过是改了点细节的地方~
对于可以环形的处理我觉得最简单实用的方法就是数组开大一倍，然后固定长度枚举起点就好了
令f(i,j)表示从第i个珠子到第j个珠子所能达到的最大值
r(i)表示第i个珠子的头标记
则有状态转移方程
f(i,j)=max{f(i,k)+f(k+1,j)+r(i-1)*r(k)*r(j)}
状态转移方程都出来了就随便推一推就好了~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int f[200][200];
int a[200];
int n;
int ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i+n]=a[i];
	for(int k=2;k<=n;k++)//枚举j-i+1即长度
		for(int i=1;i<=n;i++)
		{
			int j=i+k-1;
			for(int r=i;r<j;r++)
			{
				if(r>=n)
					f[r+1][j]=f[r+1-n][j-n];
				f[i][j]=max(f[i][j],f[i][r]+f[r+1][j]+a[i]*a[r+1]*a[j+1]);//末尾的尾标记等于下一个珠子的头标记~
			}
		}
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i][i+n-1]);//枚举所有起点可能情况，长度必须为n
	cout<<ans<<endl;
	return 0;
}
     