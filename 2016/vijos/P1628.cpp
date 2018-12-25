/*
好题~
首先我们看到如果这道题去掉超级情敌的限制
这就是一个二位费用的背包
求用a,b的两种时间尽可能选取最多的威胁值
这样剩下的就是无法解决的威胁值就可以达到最小化了
但是有了超级情敌就不一样了
首先我们考虑超级情敌的情况
我们只有3种选择
1.不消灭	2.第一个月消灭	3.第二个月消灭
因为超级情敌数量m最大只有4个
所以我们完全可以dfs枚举超级情敌的情况
一共有3^m种情况
那么我们就可以对于已经选取好超级情敌的情况开始dp
对于超级情敌	因为dfs已经考虑故跳过
对于没有被保护的情敌	可以第一个月消灭也可以第二个月消灭(取最优)
对于被保护的情敌
1.如果该超级情敌被第一个月消灭,那么该情敌既可以第一个月消灭也可以第二个月消灭(取最优)
2.如果该超级情敌被第二个月消灭,那么该情敌只能第二个月被消灭
3.如果该超级情敌没有被消灭,那么该情敌不能被消灭
这样我们完全可以用0/1背包来解决
这里需要注意的是	我们的0/1背包不能用二维解决！
而是一定要三维
因为我们如果用二维是不可能保证对于某一个两个月都可以消灭的情敌
递推第二个月的时候他是无关第一个月的
通俗一点就是	可能有一个"物美价廉"的情敌
在0/1背包递推的时候	因为过于优被算了第一个月消灭一次第二个月又消灭一次
所以我们一定要用三维
这里可以用滚动数组优化一下(但是我比较懒就没写咯)
复杂度O(n*a*b*2^m)
注意储存答案要用long long不然倒数第二个点会炸
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define LL long long
const int MAXN=55;
const int MAXT=105;
const int INF=(1<<30)-1;
bool is[MAXN];
int c[MAXN];
int use[MAXN];
int fa[MAXN];
int w[MAXN],t[MAXN];
LL f[MAXN][MAXT][MAXT];
LL ans,sumw;
int n,m;
int a,b;

void init()
{
	int tot,x;
	scanf("%d%d",&a,&b);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i],&t[i]);
		sumw+=w[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&c[i],&tot);
		is[c[i]]=1;
		for(int j=1;j<=tot;j++)
		{
			scanf("%d",&x);
			fa[x]=c[i];
		}
	}
}

inline void upadate(int& i,int& j1,int& j2,int t,int c)
{
	if(c==1)
		f[i][j1][j2]=max(f[i][j1][j2],f[i-1][j1-t][j2]+w[i]);
	else
		f[i][j1][j2]=max(f[i][j1][j2],f[i-1][j1][j2-t]+w[i]);
}

void work(int t1,int t2,LL now)
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		for(int j1=0;j1<=t1;j1++)
			for(int j2=0;j2<=t2;j2++)
			{
				f[i][j1][j2]=f[i-1][j1][j2];
				if(is[i])	continue;
				if((use[fa[i]]==1||!fa[i])&&j1>=t[i])
					f[i][j1][j2]=max(f[i][j1][j2],f[i-1][j1-t[i]][j2]+w[i]);
				if((use[fa[i]]<=2||!fa[i])&&j2>=2*t[i])
					f[i][j1][j2]=max(f[i][j1][j2],f[i-1][j1][j2-2*t[i]]+w[i]);
			}
	}
	ans=max(ans,f[n][t1][t2]+now);
}

void dfs(int cur,int t1,int t2,LL now)
//cur当前考虑的超级情敌,t1第一个月剩余时间,t2第二个月剩余时间,now当前消灭的超级情敌的w
{
	if(t1<0||t2<0)
		return;
	if(cur>m)
	{
		work(t1,t2,now);
		return;
	}
	int& p=c[cur];
	use[p]=1;
	dfs(cur+1,t1-t[p],t2,now+w[p]);
	use[p]=2;
	dfs(cur+1,t1,t2-2*t[p],now+w[p]);
	use[p]=3;
	dfs(cur+1,t1,t2,now);
}

void out()
{
	printf("%lld\n",sumw-ans);
}

int main()
{
	init();
	dfs(1,a,b,0LL);
	out();
}
     