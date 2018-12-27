/*
一个标准的贪心算法了
就是乘船问题的改版而已
我们维护左右指针
考虑最右边价值最大的物品
如果他能和左边价值最小的物品一起
那么就一起不然就只能自己独立成为一个物品组
这样不会丢失最优解
可以看算法竞赛入门经典
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int w,n;
int a[30003];
int ans;

void init()
{
	scanf("%d%d",&w,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
}

void work()
{
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l]+a[r]<=w)
		{
			l++;	r--;	
			ans++;
		}
		else
		{
			r--;	ans++;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	init();
	work();
}
     