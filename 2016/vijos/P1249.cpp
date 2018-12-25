/*
并查集+分组dp
我们看到这个物品爆炸的传递性
很明显就能想到并查集
那么我们可以用并查集处理出哪些物品是不能一起放的
(不能放的都加到同一个集合去,最后同一个集合内的就不能一起放了)
这样我们就把物品分成了若干组
就转变为了一个分组背包的问题
对于一个组内的物品	我们只能选一个
建议去看一下背包九讲
就很好写啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=1005;
int p[MAXN],w[MAXN];
int fa[MAXN];
int f[MAXN];
vector<int> g[MAXN];
int n,maxw,k;

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void init()
{
	scanf("%d%d%d",&n,&maxw,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i],&w[i]);
}

void initfa()
{
	int x,y;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		int fx=find(x);	int fy=find(y);
		if(fx!=fy)
			fa[fx]=fy;
	}
	for(int i=1;i<=n;i++)
		g[find(i)].push_back(i);
}

void DP()
{
	for(int i=1;i<=n;i++)
		if(g[i].size())
			for(int j=maxw;j>=0;j--)
				for(int k=0;k<g[i].size();k++)
					if(j>=w[g[i][k]])
						f[j]=max(f[j],f[j-w[g[i][k]]]+p[g[i][k]]);
	printf("%d\n",f[maxw]);
}

int main()
{
	init();
	initfa();
	DP();
}
     