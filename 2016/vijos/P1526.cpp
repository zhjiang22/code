/*
NOIP考前好题求++rp~
首先我们看到这道题目的时候	很容易想到n这么小是不是可以搜索来做
但是发现复杂度有点高~(枚举ans)
仔细想一下其实答案是具有单调性的
随着汉诺塔数量的增加	能放的圆盘数量一定是不减的
所以我们可以来二分ans以降低复杂度
(关于二分边界的话其实我们可以先写一个枚举打出n=15时的ans是600多改成二分即可)
这里我的二分范围是0-700了
那么我们考虑如果验证一个ans是否可行(check)
因为是要按顺序来的
所以我们考虑对于两个数x y
如果x+y是质数	我们连一条有向边x->y(注意一定要是有向边因为有顺序限制)
这样我们建立出了一个有向图
对于一条边的两个顶点	我们可以选择放在一个塔上
那么我们成功建模:
对于一个有向图,至少需要用多少条不相交路径才能将它盖住
那么我们有这样的定理
最小路径覆盖=顶点总数-最大匹配数
这样我们对于二分的ans
只需要跑一遍匈牙利算法(网络流)
求出最小路径覆盖判断是否小于或者等于ans即可
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

const int MAXN=700;
int vis[MAXN+5],match[MAXN+5];
int g[MAXN+5][MAXN+5];
int n;

bool is_prime(int x)
{
	if(x==2)
		return 1;
	int k=sqrt(x);
	for(int i=2;i<=k;i++)
		if(x%i==0)
			return 0;
	return 1;
}

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=MAXN;i++)
		for(int j=i+1;j<=MAXN;j++)
			if(is_prime(i+j))
				g[i][j]=1;
}

bool dfs(int& u,int& x)
{
	for(int i=1;i<=x;i++)
		if(g[u][i]&&!vis[i])
		{
			
			vis[i]=1;
			if(!match[i]||dfs(match[i],x))
			{
				match[i]=u;
				return true;
			}
		}
	return false;
}

bool check(int x)
{
	int ans=0;
	memset(match,0,sizeof(match));
	for(int i=1;i<=x;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i,x))
			ans++;
	}
	return (x-ans)<=n;
}

void work()
{
	int ans=0;
	int l=0,r=MAXN-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else
			r=mid-1;
	}
	printf("%d",ans);
}

int main()
{
	init();
	work();
}