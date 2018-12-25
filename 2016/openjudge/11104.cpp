/*
直接二分切割标准长度就好了
考虑到浮点数很难处理
而所有我们涉及到的浮点数这里都是2位小数
干醋就直接把它*100转换为整数来处理
更加方便快捷
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXN=10005;
int a[MAXN];
int n,k;
int maxv;
double x;

bool check(int mid)
{
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=(a[i]/mid);
	return ans>=k;
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=x*100;
		maxv=max(a[i],maxv);
	}
	int l=1,r=maxv;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	double x=(l-1)/(double)100;
	printf("%.2lf\n",x);
	return 0;
}
     