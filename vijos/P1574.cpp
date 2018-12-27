/*
贪心+背包即可~~
一开始以为是贪心但是发现没法做
有了k这个限制条件导致必然是贪心无法解决的
首先我们很容易想清楚这样的事实
如果已经确定了砍哪几棵树
必然是应该先砍掉那些掉落金币掉的更快的树
这样才可以减小损失
所以我们先按照掉落的速度从大到小排好序
这样可以保证先选到掉的快的
那么我们就可以开始进行dp了
到了这一步dp就已经很简单了
和0/1背包的一维优化一样的
f[j]表示选了j棵树的最大价值
k天是背包容量
砍一棵用一天是物品体积
物品的价值应该是当前被第j个选取的时候
s-v*(j-1)
加不加<0特判都一样因为都不会影响f[]
同时还要注意最终答案不一定是f[k]
所以要遍历所有可能答案~~窝直接加个ans每次比较
保证不会丢失最优解~~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
struct tree
{
	int s,v;
	bool operator<(const tree& c)const
	{
		return v>c.v;
	}
}a[MAXN];
int f[MAXN];
int n,k;

void init()
{
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].s);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].v);
}

inline int getw(int i,int j)
{
	return a[i].s-a[i].v*(j-1);
}

void DP()
{
	sort(a+1,a+n+1);
	int ans=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=k;j>=1;j--)
		{
			f[j]=max(f[j],f[j-1]+getw(i,j));
			ans=max(ans,f[j]);
		}
	cout<<ans<<endl;
}

int main()
{
	while(scanf("%d%d",&n,&k)==2&&n&&k)
	{
		init();
		DP();
	}
}	
     