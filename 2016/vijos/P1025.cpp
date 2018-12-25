/*
裸题~很明显的0/1背包问题
因为每个活动要么选择一次要么不选
时间是容量	活动是物品
直接一次0/1背包就能过了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int f[1005];
int n,T;

int main()
{
	int w,t;
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&w,&t);
		for(int j=T;j>=t;j--)
			f[j]=max(f[j],f[j-t]+w);
	}
	printf("%d\n",f[T]);
	return 0;
}
     