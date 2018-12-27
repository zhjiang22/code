/*
还是逆序对问题
100万的数据nlogn还是有点紧的
但是是可以的
注意输入
题目描述有误
输入数据ai有0的情况
所以如果用树状数组的话还要加上1来弄
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define lowbit(x)	(x)&(-x);
const int MAXN=1000005;
long long ans;
int a[MAXN];
int c[MAXN];
int maxw;
int n;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxw=max(maxw,a[i]+1);
	}
}

int sum(int x)
{
	int tot=0;
	while(x>0)
	{
		tot+=c[x];
		x-=lowbit(x);
	}
	return tot;
}

void update(int x,int d)
{
	while(x<=maxw)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		ans+=i-sum(a[i]+1)-1;
		update(a[i]+1,1);
	}
	printf("%lld\n",ans);
}

int main()
{
	init();
	work();
}
