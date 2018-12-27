/*
这道题一开始看到觉得很不好搞(可能是窝太弱惹~)
然后想了很久突然想到以前做过一道题
思想是相通的
我们对于这个给出的数b	比他大的数变成1 比他小的数变成-1	他自己是0
那么问题就变成了往左往右延伸使和为0即可
那么这样就有点中途相遇法的味道了？
害怕><QAQ
那么我们因为是要连续的	所以我们可以预处理一下s[i]
其中以p为分界线向左预处理出向左可以得到的和
同理向右预处理一遍
那么问题就变成了在左端的一个x要在右端找到一个-x了
如果是朴素的查找的话10万的数据O(n^2)必炸
那么我们就可以选择hash的方法来在O(nlogn)的时间内找到这个值得个数
当然窝们还有更好的方法
即计数排序的思想咯
我们用一个c[i]来表示左部的s[j]==i的j的个数
然后再直接枚举左边的所有数就可以直接O(n)枚举O(1)查找了
当然窝们还不能忘了s[i]==0的情况
即只在一边就可以的情况也要加上
这样这道题就做出来啦~
注意咯因为s[i]取负数后窝们是C++党啊所以就只能手写个扩大防止负数的了
真心很棒~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
int a[MAXN<<1];
int c[MAXN<<1];
int s[MAXN];
int n,b,p;
int ans;

inline int Hash(int x)
{
	return x+MAXN;
}

void init()
{
	int x;
	cin>>n>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x>b)	a[i]=1;
		else	if(x<b)	a[i]=-1;
		else	p=i,a[i]=0;
	}
}

int main()
{
	init();
	for(int i=p-1;i>=1;i--)
		s[i]=s[i+1]+a[i];
	for(int i=p+1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<p;i++)
		c[Hash(s[i])]++;
	for(int i=p+1;i<=n;i++)
	{
		if(c[Hash(-s[i])])
			ans+=c[Hash(-s[i])];
	}
	for(int i=1;i<=n;i++)
		if(s[i]==0)
			ans++;
	cout<<ans<<endl;
	return 0;
}
     