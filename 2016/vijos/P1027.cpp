/*
呼呼~只能说语文没学好这道题真心做的累呀23333
一开始看到这道题想都没想就想到了toposort+关键路径(无视语病问题)
然后突然发现好像不是这个意思
仔细一看	突然感觉好像不需要AOV?
或者说不能AOV?
倒是有点像求最长路~
手算一下样例自己找下规律
发现最长路的确是可以的	考虑到n,m都很小
直接可以Floyd求最长路~
对于输入的点和边构成的G(V,E)Floyd更新最长路(注意结点数应该是n+1)
然后一定要注意，我们选择的最长路的起点和终点是固定的，只能是1和n+1
所以就直接输出a[1][n+1]就好啦
对于路径上的点的判断就简单啦~
一个循环找一下所有点,如果有a[1][i]+a[i][n+1]==a[1][n+1]
那么就是路径上的点，输出即可
这道题就做出来了	所以一定要细心不要被一大串的题目弄昏了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int m;
int a[130][130];

void init()
{
	int x,y,w;
	scanf("%d",&n);		n++;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		a[x][y]=w;
	}
}

void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					if(a[i][k]>0&&a[k][j]>0)
						a[i][j]=max(a[i][j],a[i][k]+a[k][j]);
}

void output()
{
	printf("%d\n",a[1][n]);
	for(int i=1;i<=n;i++)
		if(a[1][i]+a[i][n]==a[1][n])
			printf("%d ",i);
}

int main()
{
	init();
	Floyd();
	output();
}
     