/*
n<=1000直接O(n^2)枚举就好啦~
题目描述不太清楚啊
竟然还可以两层楼是相邻的
中间那层楼直接除以二取整算
也是醉了
反比例交叉相乘就好
会有警察数为0的情况
如果用分数就RE了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int a[MAXN];
int n,b;

void init()
{
	cin>>n>>b;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}

void out(int x)
{
	int sum=0;
	if(b==0)
		for(int i=1;i<=x;i++)
			sum+=a[i];
	else
		for(int i=n;i>=x;i--)
			sum+=a[i];
	cout<<x<<" "<<sum<<endl;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(i*a[i]==j*a[j])
			{
				out((i+j)>>1);
				return 0;
			}
	return 0;
}
     