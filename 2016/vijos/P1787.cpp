/*
一个超级简单的模拟？
然而弄了我一个晚上
一开始发现直接裸的模拟会爆
后面就开了一个c[]记录每层有多少个有楼梯的
对于这个标记x
我们去掉c[]周期就好了
就是转一圈等于没转
然后开个c[]
本来是MAXN写成了MAXM
然后难道不应该是RE？
结果是TLE
就纳闷了弄了一晚上
哭了出来
OI再见
一个小时++就没了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
const int MAXM=105;
const int mod=20123;
struct node
{
	int have;
	int x;
}a[MAXN][MAXM];
int c[MAXN];
int n,m;
int s;
long long ans;

void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d%d",&a[i][j].have,&a[i][j].x);
			if(a[i][j].have)
				c[i]++;
		}
	scanf("%d",&s);
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		int x=a[i][s].x;
		int tot=0;
		s--;
		ans=(ans+x)%mod;
		while(x>c[i])
			x-=c[i];
		while(tot<x)
		{
			s=(s+1)%m;
			tot+=a[i][s].have;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
     