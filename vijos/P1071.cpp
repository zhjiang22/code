/*
此题很明显是经典的0/1背包问题，对于每张牌都有选或不选的办法
则做法已经很明确
1.dfs深搜枚举所有情况,O(2^n)复杂度过高
2.动态规划
基础思路：设bool数组f[i][j]为选到第i张牌的时候重量为j的可能性
但是注意，这里要求要判断多个解的情况，所以不能光用bool数组了
同时我们考虑0/1背包的暗箱思想+一维优化，则可以得出这样的状态描述
	f[j]表示某层容量为j时的情况
	f[j]==0则有达不到，f[j]==1则有答案，f[j]==-1则说明有多解
用f[j]=-1表示多解而不用2什么的是为了更好的方便输出答案(多解无解都可以直接输出f[sum])
则根据以上状态有状态转移方程
f[j]=
{
	1,f[j-a[i]]==0;
	-1,f[j-a[i]]>0;
}
每次j从sum倒推到a[i]即可，每次递推都是建立在上一次基础上
这是0/1背包的基本功了
容易知道如果某个f[j]==-1了，那么一直到最后不管推多少次都还是-1
所以容易得到该算法的正确性
打印解的时候我们要打印的应该是装满sumw-w的方案
这里可以dfs也可以直接迭代
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int MAXW=100005;
int f[MAXW],pre[MAXW];
int ans[MAXN];
int a[MAXN];
int n,w,sumw;

void init()
{
	scanf("%d",&w);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sumw+=a[i];
	}
}

void DP()
{
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=sumw;j>=a[i];j--)
			if(f[j-a[i]]>0)
			{
				if(f[j]>0)
					f[j]=-1;
				else	if(f[j]==0)
				{
					f[j]=1;
					pre[j]=i;
				}
			}
	f[0]=0;//会有w=0的点
}

void print_ans()
{
	w=sumw-w;
	if(f[w]<=0)
		printf("%d\n",f[w]);
	else
	{
		int cnt=0,cur=w;
		while(cur)
		{
			ans[++cnt]=pre[cur];
			cur-=a[pre[cur]];
		}
		for(int i=cnt;i>=1;i--)
			printf("%d ",ans[i]);
		printf("\n");
	}
}

int main()
{
	init();
	DP();
	print_ans();
}
     