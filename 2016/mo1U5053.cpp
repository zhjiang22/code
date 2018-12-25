#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int a[MAXN];
int f[MAXN][MAXN];
int maxw[MAXN][MAXN];
int minw[MAXN][MAXN];
int n;

void init()//O(n^2)预处理区间最大最小
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		maxw[i][i]=minw[i][i]=a[i];
		for(int j=i+1;j<=n;j++)
		{
			maxw[i][j]=max(maxw[i][j-1],a[j]);
			minw[i][j]=min(minw[i][j-1],a[j]);
		}
	}
}

void DP()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			
		}
	}
}

int main()
{
	init();
	DP();
}
     