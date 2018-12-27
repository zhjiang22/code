/*
f[i][j]表示用i个人能否加到j血
枚举每一个人对f数组的改变
用刷表法完成
这样的话我们就可以找到第一个最接近sum/2的j
使得f[n/2][j]为true
就是答案了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXN=205;
const int MAXV=8050;
const int INF=(1<<30)-1;
int a[MAXN];
int f[MAXN][MAXV];
int n,n2,sum;

void init()
{
	scanf("%d",&n);
	n2=n>>1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
}

void DP()
{
	f[0][0]=1;
	for(int k=1;k<=n;k++)
		for(int i=n2;i>=0;i--)
			for(int j=sum-a[k];j>=0;j--)//顺序无关
					if(f[i][j])
						f[i+1][j+a[k]]=1;
	for(int j=sum/2;j>=0;j--)
		if(f[n2][j])
		{
			printf("%d %d\n",j,sum-j);
			return;
		}
}

int main()
{
	init();
	DP();
}
     