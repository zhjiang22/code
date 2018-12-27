/*
首先有这么一个结论：对任意n：1,2,4,8,......总是一个最优方案.
那么很容易知道	最少个数为log2n+1
假设第k-1个数是a[k-1],前k-1个数能达成的最大的连续的数是sum,
那么第k个数的范围一定是a[k-1]+1到sum+1.
然后用动态规划来求解方案总数
用f[count,last,max]
表示count个数、最后的数（也是最大的）为last、能组成1到max中所有正整数的方案数
然后状态转移方程就很容易出来了
仔细看代码叭~好晚了要睡觉咯~233333
注意到n最大1000
所以ans最大为10
所以第一维开到11	二三维最大就是1000咯
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn=1005;
int n;
int ans;
int tot;
int f[11][maxn][maxn];

int main()
{
	cin>>n;
	ans=(int)log2(n)+1;
	f[1][1][1]=1;
	for(int i=1;i<ans;i++)
		for(int j=i;j<=(1<<(i-1));j++)
			for(int k=i;k<=((1<<i)-1);k++)
				if(f[i][j][k])
					for(int p=j+1;p<=k+1;p++)
					{
						if(p+k<=n)//如果加起来在范围内
							f[i+1][p][k+p]+=f[i][j][k];
						else//加起来不在范围内
							f[i+1][p][n]+=f[i][j][k];
					}
	for(int i=1;i<=n;i++)
		tot+=f[ans][i][n];
	cout<<ans<<" "<<tot<<endl;
	return 0;
}
