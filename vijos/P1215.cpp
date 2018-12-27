/*
一种很经典的DP吧
OTZ涨姿势了
我们来看这个题目
第一感觉就是一个最经典的回溯？OTZ
水题啊直接写了个裸的dfs
然后70分
果然dfs太慢了过不了数据
那我们再来看为什么dfs会很慢？
因为这道题目中有太多的重复子问题了
所以我们加上个动态规划DP
解决重复子问题最好的就是记忆化搜索了
我们可以知道其实这就是个枚举每位上的数字的情况
而肯定是具有无后效性的
什么意思呢
比如我们有这么两个未接完的序列
1 3 5 3 x
3 6 7 2 x
虽然这两个序列前面四个不一样
但是第五个都是一样的
而且以x开头的满足条件的序列是不受前面的影响的
所以我们处理到这两个式子的时候
都要计算一遍以x开头长度为(L-4)的序列有多少种
而这就成了重复问题
我们就可以直接用一个f[last][cur]表示
当前第cur个位置是last后面可以有多少种情况
然后做的时候直接记忆化搜索就好了
初始化-1以免误判记忆化
然后ans要开到long long
不然WA一个点
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
long long f[MAXN][MAXN];
long long ans;
int a[MAXN];
int n,k;

void init()
{
	scanf("%d%d",&k,&n);
}

long long dfs(int cur,int last)
{
	if(cur>n)
		return 1;
	long long& o=f[cur][last];
	if(o)
		return o;
	for(int i=0;i<k;i++)
		if((i!=0||last!=k+1)&&i!=last+1&&i!=last-1)
			o+=dfs(cur+1,i);
	return o;
}

void work()
{
	ans=dfs(1,k+1);
	printf("%lld\n",ans);
}

int main()
{
	init();
	work();
}
     