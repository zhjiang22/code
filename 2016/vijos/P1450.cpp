/*
二分最大速度即可
注意精度
难点主要还是在怎么判断是否满足条件上Orz
我太弱啊
随手写一下就好很好理解的
然后精度要注意
还有不要用cin啊
稳稳的6000ms
一用scanf就直接1000ms了
23333333
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=200000;
const double INF=10000000;
const double minv=1e-5;
struct node
{
	double x,y,s;
}a[MAXN];
int n;

bool check(double v)
{
	double time=0;
	for(int i=1;i<=n;i++)
	{
		time+=a[i].s/v;
		if(time<=a[i].y)
			time=max(time,a[i].x);
		else
			return false;
	}
	return true;
}

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].s);
}

int main()
{
	init();
	double l=minv,r=INF;
	while(r-l>=minv)
	{
		double mid=(l+r)/2.0;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%.2lf\n",l);
	return 0;
}
     