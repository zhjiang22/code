/*
USACO的一道题目改了个背景~好题
搜索+背包dp~
我们看到我们根本很难去搜索
如果去枚举选取哪些再判断可行的话
那么我们会有2^100种情况检查
必然是会爆炸的~
这样我们其实可以采用迭代加深搜索的方法
这样完全是可行的
因为这样完全可以减少一些使用了全部水桶的方案
只要找到一个解就退出也是挺快的
即我们从1...n枚举最大深度上线maxd
然后再枚举选取这maxd个元素~这里用dfs来解决
选取好后开始检查这maxd个元素是否可以填满V容量
这像不像是背包?
因为每个水桶可以用无限多次
所以我们可以用完全背包来解决
因为只需要判断是否能装满所以我们用f[]的0或1来表示能否到达
然后完全背包刷一遍即可
这里可以用递推地方法也可以用递归的方法~
窝两个都写了一下
递归会比递推快很多~因为递推要全部刷一遍复杂度是O(nV)的
而递归递归下去找到一个可行解就是连续递归返回
所以效率高了很多(220ms-45ms)
这样就可以解决这道题了~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int MAXV=21000;
int f[MAXV];
int a[MAXN];
int v[MAXN];
int V,n;
int maxd;

void init()
{
	scanf("%d%d",&V,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
}

void print()
{
	printf("%d ",maxd);
	for(int i=1;i<=maxd;i++)
		printf("%d ",a[i]);
	exit(0);
}

/*bool check(int& V)
{
	memset(f,0,sizeof(f));	f[0]=1;
	for(int i=1;i<=maxd;i++)
		for(int j=0;j<=V;j++)
			if(f[j]&&j+a[i]<=V)
				f[j+a[i]]=1;
	return f[V];
}*/

bool check(int x)
{
	int &s=f[x];
	if(s!=-1)
		return s;
	if(x==0)
		return s=1;
	for(int i=1;i<=maxd;i++)
		if(x>=a[i]&&check(x-a[i]))//第一次进入是从此入口递归下降
			return s=1;
	return s=0;
}

void dfs(int depth,int k)//当前在选第cur个位置,到了第k个水桶
{
	if(depth==maxd+1)
	{
		memset(f,-1,sizeof(f));
		if(check(V))
			print();
		return;
	}
	if(k>n)
		return;
	a[depth]=v[k];
	dfs(depth+1,k+1);//选了了该水桶
	dfs(depth,k+1);//没选该水桶(巧妙利用了覆盖)
}

void id_dfs()
{
	sort(v+1,v+n+1);
	n=unique(v+1,v+n+1)-v-1;//优化程度不大(数据重合少)
	for(maxd=1;maxd<=n;maxd++)
		dfs(1,1);
}

int main()
{
	init();
	id_dfs();
}
     