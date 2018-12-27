/*
弱弱的数据导致直接枚举就能过还是秒过...
唯一要注意到的就是
这个连续的序列长度一定要大于1
所以枚举起点的时候必须要从0-m-1方可
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int m;
int sum;

void init()
{
	scanf("%d",&m);
}

void work()
{
	for(int i=0;i<m;i++)
	{
		sum=0;
		int j;
		for(j=i;sum<m;j++)
			sum+=j;
		if(sum==m)
			printf("%d %d\n",i,j-1);
	}
}

int main()
{
	init();
	work();
}
     