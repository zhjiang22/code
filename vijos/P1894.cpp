/*
最小值最大~~很明显是二分了~
但是判定有点小复杂了~
因为是环形分割~
所以我们应该拉成一条链并且长度为两倍~~
那么我们就可以枚举以i为起点i+n为终点
开始切割
这样的话我们是应该直接贪心找到一个最小的s[p]-s[i]>=x
这样必然不会丢失最优解~
同理找到了p再找个q
再判断一下s[i+n]-s[q]是否满足条件
这样就完成了判定了~~
同时注意到输入数据很大啊
不仅是s[]
a[]也要long long
不然只有20分~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
long long a[MAXN];
long long s[MAXN];
long long ans;
int n;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		s[i+n]=s[i+n-1]+a[i];
}

bool check(long long x)
{
	int p=1,q=1;
	for(int i=1;i<=n;i++)//枚举起点
	{
		while(p<=i+n&&s[p]-s[i]<x)	p++;
		if(p==i+n+1)
			return false;
		while(q<=i+n&&s[q]-s[p]<x)	q++;
		if(q==i+n+1)
			return false;
		if(s[i+n]-s[q]>=x)
			return true;
	}
	return false;
}

void Work()
{
	long long l=0,r=s[n];
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
			ans=max(ans,mid),l=mid+1;
		else
			r=mid-1;
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	Work();
}
     