/*
真好题~~~
这道题有二分做法这里复杂度是O(Xlogn)
也有神犇的O(n)做法
http://www.cnblogs.com/iwtwiioi/p/4015748.html
这里我用的是二分做法了
很明显最大值最小我们可以二分+判定
所以我们可以二分这个一号到别的城市的最大距离
首先有一个玄学证明要搞清楚
如果我们要建立虫洞的话左边的虫洞一定要建在1号首都
这个可以数学证明~
引用题解中林小雅的证明
{
对于第一个虫洞必须在1号城市的证明 简单来说就是这样
设我们现在要去K城市 且虫洞入口在A 出口在B 显然A在B前会更优
那么我们一共有两种可能的方案到达那里
1. 直接走过去 路程是D[1,K]
2. 通过虫洞 路程是D[1,d]+D
这里D[X,Y]表示两城市X,Y的直线距离
那么可以注意到 第二种情况的D[1,d]并不随B点和K点的选择变化而变化
因此D[1,d]当然是取得越小越好
那么取1点就可以使得D[1,1]=0达到最小
证毕
}
所以我们就可以很容易在O(logn)的时间中判断是否可行
我们设一开始找到的点为p	那么1-p-1所有的店都是可以在二分值内到达的
先将虫洞的位置设在第一个到1距离>mid的点，设为p
这个时候我们发现p点这个一定是要有个虫洞来改善它的距离
那么我们贪心思想找到一个最远的但却又能让它在二分值之内到达的~
所以二分找到第一个q使得d[q]>d[p]+x的q
那么q-1满足d[q-1]<d[p]+x
这样我们就在这里建立个虫洞~
这样的话保证了1-q-1全部距离都是满足的了
那么我们还需要判断剩下的城市能不能在二分值内到达
所以我们就要看看最大的那个d[n]是否会大于d[q-1]+x
这样就可以完成判断
而p q我们都可以通过二分查找来找到~
这样做一定是最优的。
（因为要想满足全部条件，首先局部必须满足，否则就无法满足全部条件，因此一步一步的考虑）
可以画一个图理解一下
二分好题~~
同时也是单调性好题~可以尝试O(n)做法
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=200005;
int d[MAXN];
int T;
int n;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
}

int find(int x)
{
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(d[mid]<=x)
			l=mid+1;
		else
			r=mid-1;
	}
	return l;
}

bool check(int x)
{
	int p=find(d[1]+x);
	if(p==n+1)
		return true;
	int q=find(d[p]+x);
	if(q==n+1)
		return true;
	return d[n]<=d[q-1]+x;
}

void work()
{
	int l=0,r=d[n]-d[1];
	int ans=(1<<30)-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		//cout<<mid<<endl;
		if(check(mid))
			ans=min(ans,mid),r=mid-1;
		else
			l=mid+1;
	}
	printf("%d\n",ans);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		init();
		work();
	}
}
     