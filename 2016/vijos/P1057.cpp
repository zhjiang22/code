/*
一个很经典类型的dp~
如果用悬线法或者单调栈因为数据不大所以特判一下也是可以AC的
但是有更简单的dp做法
我们f[i,j]表示点(i,j)为正方形右下角的点时的最小边长
那么一个以(i,j)为右下角的正方形能否接上别的更大的正方形
必然是和(i-1,j-1)	(i-1,j)	  (i,j-1)有关
这样的话我们就可以尝试f[i][j]的转移
根据短板原理咯~f[i][j]到底能扩展到多大必然是三个中的最小值
这样就会有f[i][j]=min(f[i-1][j-1],f[i-1][j],f[i][j-1])+1
前提是(i,j)是完整的
这样我们很容易看到其实如果我们按照1...n 1...m输入的顺序
其实对于每个f[i][j]
它需要的三个状态已经推了出来
这样的话其实根本没有必要储存这个图
而是可以直接一个一个读入(i,j)的情况
如果(i,j)不是完好的话那么必然f[i][j]就是0
不需要任何操作
如果是完好的那么就可以尝试转移了~
这样复杂度就是O(nm)的
完全可以直接秒杀
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int f[MAXN][MAXN];
int n,m;
int ans;

void init()
{
	scanf("%d%d",&n,&m);
}

void DP()
{
	int tmp;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&tmp);
			if(tmp)
				f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
			ans=max(ans,f[i][j]);
		}
	printf("%d\n",ans);
}

int main()
{
	init();
	DP();
}
     