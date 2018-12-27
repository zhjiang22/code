/*
一道典型的背包型dp?
因为一共就只有1 2 3 4四种牌
那么我们就直接用b[5]来储存每种牌的数量
f[i][j][k][d]表示1的牌用了i张，2的牌用了j张，3的牌用了k张，4的牌用了d张所能达到的最大值
则状态转移方程就很明显了
详细见代码
注意细节
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=42;
const int MAXN=355;
int f[maxn][maxn][maxn][maxn];
int a[MAXN];
int b[5];
int n,m;


int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int x;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		b[x]++;
	}
	f[0][0][0][0]=a[1];
	for(int i=0;i<=b[1];i++)//要从0开始推
		for(int j=0;j<=b[2];j++)
			for(int k=0;k<=b[3];k++)
				for(int d=0;d<=b[4];d++)
				{
					int cur=i*1+j*2+k*3+d*4+1;
					if(i>=1)	f[i][j][k][d]=max(f[i][j][k][d],f[i-1][j][k][d]+a[cur]);
					if(j>=1)	f[i][j][k][d]=max(f[i][j][k][d],f[i][j-1][k][d]+a[cur]);
					if(k>=1)	f[i][j][k][d]=max(f[i][j][k][d],f[i][j][k-1][d]+a[cur]);
					if(d>=1)	f[i][j][k][d]=max(f[i][j][k][d],f[i][j][k][d-1]+a[cur]);
				//注意此处的+a[cur]要放入max中而不能外面单独来一个f[i][j][k][d]+=a[cur]
				//因为在推f[0][0][0][0]的时候会多加一次，如果一定要在外面则要特判此情况
					/*
					if(i==0&&j==0&&k==0&&d==0)
						continue;
					else
						f[i][j][k][d]+=a[cur];
						*/
				}
	cout<<f[b[1]][b[2]][b[3]][b[4]]<<endl;
	return 0;
}
     