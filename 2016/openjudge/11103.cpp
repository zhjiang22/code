/*
二分这条分割线就好
因为R会很大但是实际矩形范围并没有那么大
所以记录一下二分边界maxr最右边的可能
然后处理一下左边
ans记录是否有相差为0的答案
如果没有则还要特判一下
使左边矩形面积尽可能大
即l值尽可能++
这样就可以了
注意细节处理
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const long long MAXN=10005;
struct node
{
	long long x,y,w,h;
	long long s;
}a[MAXN];
long long R;
long long n;
long long maxr;
long long ans=-1;

long long solve(long long x)
{
	long long sumr=0,suml=0;
	for(long long i=1;i<=n;i++)
	{
		if(a[i].x+a[i].w<=x)
			suml+=a[i].s;
		else	if(a[i].x>=x)
			sumr+=a[i].s;
		else
		{
			suml+=(x-a[i].x)*a[i].h;
			sumr+=(a[i].x+a[i].w-x)*a[i].h;
		}
	}
	return suml-sumr;
}

void init()
{
	cin>>R;
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y>>a[i].w>>a[i].h,
		maxr=max(maxr,a[i].x+a[i].w),
		a[i].s=a[i].w*a[i].h;
}

int main()
{
	init();
	long long l=0,r=maxr;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		long long x=solve(mid);
		if(x==0)
		{
			if(mid>=ans)
				ans=mid;
			l=mid+1;
		}
		else	if(x<0)
			l=mid+1;
		else
			r=mid-1;
	}
	if(ans!=-1)
		cout<<ans<<endl;
	else	
	{
		while(solve(l)==solve(l+1)&&l<R)//使大矩形面积尽可能大
			l++;
		cout<<l<<endl;
	}
	return 0;
}
