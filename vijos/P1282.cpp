/*
排序水题啊~
唯一的坑点就在于附加权值
D[i]还要-1
一开始差点被坑了
也不多说了这种题
Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=50005;
struct P
{
	int w,idx;
	bool operator<(const P& b)const
	{
		return w>b.w||(w==b.w&&idx<b.idx);
	}
}a[MAXN];
int e[10];
int n,k;

void init()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<10;i++)
		scanf("%d",&e[i]);
	for(int i=1;i<=n;i++)
		a[i].idx=i,
		scanf("%d",&a[i].w);
}

void out()
{
	for(int i=1;i<=k;i++)
		cout<<a[i].idx<<" ";
	cout<<endl;
}

int main()
{
	init();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		a[i].w+=e[(i-1)%10];
	sort(a+1,a+n+1);
	out();
	return 0;
}
     