/*
贪心就好~~~
利用坐标来记录一下在某个行或者列隔开
能够隔开多少对讲话的
因为输入数据保证了相邻
同时每一对有且仅有一种方式可以让他们隔开
所以完全可以直接贪心选择最多的k/l个
这样我们可以先按照这个依据排出前k/l个
注意到我们输出是要按照从小到大
那么我们就可以直接再次按照编号从小到大
将这k/l个排个序
直接输出就行了~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
struct P
{
	int idx,w;
	bool operator<(const P& b)const
	{
		return w>b.w;
	}
}line[MAXN],list[MAXN];
int n,m;
int k,l,d;

inline bool cmp(const P& a,const P& b)
{
	return a.idx<b.idx;
}

void init()
{
	int x,y,x2,y2;
	scanf("%d%d%d%d%d",&n,&m,&k,&l,&d);
	for(int i=1;i<=n;i++)
		line[i].idx=i;
	for(int i=1;i<=m;i++)
		list[i].idx=i;
	for(int i=1;i<=d;i++)
	{
		scanf("%d%d%d%d",&x,&y,&x2,&y2);
		if(x==x2)
			list[min(y,y2)].w++;
		else
			line[min(x,x2)].w++;
	}
}

void work()
{
	sort(line+1,line+n+1);
	sort(list+1,list+m+1);
	sort(line+1,line+k+1,cmp);
	sort(list+1,list+l+1,cmp);
	for(int i=1;i<=k;i++)
		printf("%d ",line[i].idx);
	printf("\n");
	for(int i=1;i<=l;i++)
		printf("%d ",list[i].idx);
	printf("\n");
}

int main()
{
	init();
	work();
}
     