/*
数据范围有毒？
害怕
一个标准的RMQ问题~
lrj训练指南上也有咯~只是最小变成了最大~
窝们定义d[i][j]表示以i为起点长度为2^j的区间中元素最大值
那么久必然会有递推式
d[i][j]=min(d[i][j-1],d[i+2^j-1][j-1])
这样的话很容易在nlogn的时间内预处理出整个d[][]
然后查询的时候
我们就先找到一个k
让k满足为2^k<=r-l+1
然后以l开头 以r结尾的一个d[][]覆盖整个[l,r]
这样就可以很快地查询出答案了~
虽然这里会有重复
但是对于最值问题是没有啥关系的
注意一些端点和区间长度的加减一的关系~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=500005;
const int Mlog=30;
int a[MAXN];
int d[MAXN][Mlog];
int n,m;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
}

void preinit()
{
	for(int i=1;i<=n;i++)
		d[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i<=n;i++)
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

int RMQ(int l,int r)
{
	int k=0;
	while((1<<(k+1)<=r-l+1))
		k++;
	return max(d[l][k],d[r-(1<<k)+1][k]);
}

void question()
{
	int l,r;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		cout<<RMQ(l,r)<<endl;
	}
}

int main()
{
	init();
	preinit();
	question();
	return 0;
}
     