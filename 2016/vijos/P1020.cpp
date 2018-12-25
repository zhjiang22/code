/*
好题~	学习了~
一开始看到这题很容易想到那道经典的派(openjudge上有)
那是一道典型的二分啊~
这里也可以用到二分但是并不一样
这里我们可以二分可以满足的人的数量
首先我们要弄清这么一个事实
如果是为了满足尽可能多的人
我们满足嘴巴小的必然要比满足嘴巴大的好
这个贪心决策很容易证明的
如果同一块蛋糕一个嘴巴大的人能正好分到那一部分
那么换一个嘴巴小的必然也能分到	还有可能因此多分到几个人
所以我们可以发现先分嘴巴小的不会丢失最优解
那么我们很容易就想到先按照嘴巴大小排个序
那么我们二分这个满足人数mid后
就要考虑是否能使mouth[1]~mouth[mid]都满足
因为蛋糕的大小是不定的
所以我们可以用dfs来完成
即枚举每一个嘴巴是用哪一块来填饱
首先我们记录下蛋糕总数sum 然后维护嘴巴大小的前序和数组s[]
那么首先我们很容易想到
对于排序后的mouth数组的前序和递增数组s[]
如果总的sum比某个s[i]还要小
那么根本没必要以i为二分右界
因为不管怎么样是不可能满足的
所以我们可以先缩小二分区域
在搜索这里需要加上剪枝
我们用waste来记录当前浪费的蛋糕数量
怎么叫浪费呢	就是某一块切去这个人吃的之后连mouth[1]都满足不了了
那么剩下的这些必然是浪费了
这个只要在dfs时维护一个全局变量waste就可以了
第二个剪枝
如果对于排序后的mouth数组	dfs过程有mouth[k]==mouth[k-1]
那么我们可以直接dfs(k-1,i)
因为如果某个i不可以填满mouth[k]的话
那么mouth[k-1]必然也填不满
所以没有必要重新判断一次
这样的话可以在12个点20ms的时间内出解
还是挺快的
关键是要学会一些常用的剪枝手段~
涨姿势~！
关于二分之后答案的输出
窝太弱啦一向迷糊
干脆直接加上一个ans来记录
就万无一失啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=55;
const int MAXM=1030;
int s[MAXM];
int cake[MAXN],fcake[MAXN];
int mouth[MAXM];
int n,m,sum;
int waste,mid;
int ans;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&cake[i]);
		sum+=cake[i];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&mouth[i]);
	sort(mouth+1,mouth+m+1);
	for(int i=1;i<=m;i++)
		s[i]=s[i-1]+mouth[i];
}

bool dfs(int k,int cur)//要满足k个人,当前到了cur
{
	if(k<=0)
		return 1;
	if(sum-waste<s[mid])
		return 0;
	for(int i=cur;i<=n;i++)
		if(fcake[i]>=mouth[k])
		{
			fcake[i]-=mouth[k];
			if(fcake[i]<mouth[1])
				waste+=fcake[i];
			if(mouth[k]==mouth[k-1])
			{
				if(dfs(k-1,i))
					return 1;
			}
			else	if(dfs(k-1,1))
				return 1;
			if(fcake[i]<mouth[1])
				waste-=fcake[i];
			fcake[i]+=mouth[k];
		}
	return 0;
}

int main()
{
	init();
	while(sum<s[m])
		m--;
	int l=0,r=m;
	while(l<=r)
	{
		waste=0;
		for(int i=1;i<=n;i++)
			fcake[i]=cake[i];
		mid=(l+r)>>1;
		if(dfs(mid,1))
			l=mid+1,ans=max(ans,mid);
		else
			r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
     