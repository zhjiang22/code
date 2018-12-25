/*
二分体积就好
精度一定要注意有点坑Orz
还有二分方式一定要注意
其实一直弄不清二分的一些细节问题
然后就写了一个70分的二分
然后就是细节没有处理好
改了一下就AC了
把错误的写法留下来以示警醒(注释处)
Orz我好弱啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN=10005;
int n,f;
double a[MAXN];
double sum;

void init()
{
	cin>>n>>f;
	f++;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=double(x*x)*3.141592653589;
		sum+=a[i];
	}
}

bool check(double mid)
{
	int tot=0;
	for(int i=1;i<=n;i++)
		tot+=(floor)(a[i]/mid);
	return tot>=f;
}

int main()
{
	init();
	double l=0,r=sum;
	while(r-l>1e-5)
	{
		double mid=(l+r)/2.0;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	/*while(l<=r)
	{
		double mid=(l+r)/2.0;
		if(check(mid))
			l=mid+0.001;
		else
			r=mid-0.001;
	}*/
	printf("%.3lf\n",l);
	return 0;
}
     