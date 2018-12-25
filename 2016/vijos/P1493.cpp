/*
多进程dp，和双人矩阵取数一样的
只不过是对于相同的点，从只能取一次数字变成了只能走一次
则从判断如果相同就减一次该方格的数变成
只有不相同才可以走
f[k][i][j]表示走到第k步，第一个人在i行，第二个人在j行的所能达到的最大值
很明显k==n+m-1就是走完了
就推一下，有状态转移方程
f[k][i][j]=max1(f[k-1][i-1][j],f[k-1][i][j-1],f[k-1][i][j],f[k-1][i-1][j-1])+a[i][i1]+a[j][j1]
i和j的递推边界时k和n的更小者
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const long long INF=0x7fffff;
long long n,m;
long long a[255][255];
long long f[255][255][255];

long long max1(long long a,long long  b,long long c,long long d)
{
	long long ans;
	ans=max(a,b);
	ans=max(ans,c);
	ans=max(ans,d);
	return ans;
}
int main()
{
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
			cin>>a[i][j];
	f[1][1][1]=a[1][1];
	for(long long k=1;k<=n+m-1;k++)
	{
		for(long long i=1;i<=n&&i<=n;i++)
		{
			for(long long j=1;j<=n&&i<=n;j++)//这里限制了边界
			{
				long long i1=k-i+1;
				long long j1=k-j+1;
					if(i!=j||k==m+n-1)
						f[k][i][j]=max1(f[k-1][i-1][j],f[k-1][i][j-1],f[k-1][i][j],f[k-1][i-1][j-1])+a[i][i1]+a[j][j1];
			}
		}
	}
	cout<<f[n+m-1][n][n]<<endl;
	return 0;
}
     