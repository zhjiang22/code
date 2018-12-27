/*
二分查找+前序和
我们直接二分这个标准值w就好了
很明显二分区间是[0,max{w}]
关键是这个判断的部分
我们用前序和来处理
即对于每一个二分的w标准值
我们都用一个s数组和一个sv数组
分别记录[1,i]中大于标准值的个数和价值之和(work函数)
然后对于每一个区间只要用前序和就好了
其实挺好写的只是要注意一些细节
数据要开到long long 就好了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long s[200004],sv[200004];
struct node
{
	long long w,v;
}a[200004];
struct tion
{
	long long x,y;
}b[200004];
long long n,m,S;

void work(long long r)
{
	s[0]=sv[0]=0ll;
	for(long long i=1;i<=n;i++)
		if(a[i].w>=r)
			s[i]=s[i-1]+1,sv[i]=sv[i-1]+a[i].v;
		else
			s[i]=s[i-1],sv[i]=sv[i-1];
}

long long cal(long long r)
{
	long long ans=0ll;
	for(long long i=1;i<=m;i++)
		ans+=(s[b[i].y]-s[b[i].x-1])*(sv[b[i].y]-sv[b[i].x-1]);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	long long start=0ll,end=0ll;
	cin>>n>>m>>S;
	for(int i=1;i<=n;i++)
		{
			cin>>a[i].w>>a[i].v;
			end=max(end,a[i].w);
		}
	for(int i=1;i<=m;i++)
		cin>>b[i].x>>b[i].y;
	long long ans=9223372036854775807ll;
	while(start<=end)
	{
		long long mid=(start+end)>>1;
		work(mid);

		long long t=cal(mid);
		if(abs(t-S)<ans)
			ans=abs(t-S);
		if(ans==0)
			break;
		if(S<t)
			start=mid+1;
		else
			end=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
     