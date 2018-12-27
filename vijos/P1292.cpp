/*
一个很明显的划分型dp问题
定义f[i]表示a到i需要的最小代价
这样就解决了重复子问题
那么我们对于一个f[i]
从[a,i)尝试寻找一个断点转移过来即可
同时对断点j到i的距离分情况讨论来选择转移的方式
+C1还是+C2还是+C3
这样就直接弄出来
唯一的坑点在于INF一定要足够大
我一开始开的是(1<<30)-1
结果只有80不够大
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF=(1<<31)-1;//INF一定要足够大不然会WA
int f[10002];
int dist[10002];
int n;
int a,b;
int L1,L2,L3,C1,C2,C3;

void init()
{
	scanf("%d%d%d%d%d%d",&L1,&L2,&L3,&C1,&C2,&C3);
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	for(int i=2;i<=n;i++)
		scanf("%d",&dist[i]);
}

void DP()
{
	for(int i=0;i<=n+5;i++)
		f[i]=INF;
	f[a]=0;
	for(int i=a;i<=b;i++)
		for(int j=a;j<i;j++)
		{
				int d=dist[i]-dist[j];
				if(d<=L1)
					f[i]=min(f[i],f[j]+C1);
				else if(d<=L2)
					f[i]=min(f[i],f[j]+C2);
				else if(d<=L3)
					f[i]=min(f[i],f[j]+C3);
		}
	printf("%d\n",f[b]);
}

int main()
{
	init();
	DP();
}
     