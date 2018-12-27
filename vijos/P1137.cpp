/*
一个很简单的数论问题了~~
做法很简单
首先我们筛出100000以内的素数表
大概有9000多个~可以先试验~
这样我们对于分子分母所有的乘数都拆分成若干个质数乘积
每次除干净就好了~
这样我们用一个cnt[i]表示第i个素数还剩多少个~
分子除素数的时候应该cnt[i]++
分母除素数的时候应该cnt[i]--
这样剩下的素数就是要求的了~~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN=100005;
int vis[MAXN];
int p[MAXN/10],cnt[MAXN/10];
int n,m,l;
int ans;

void init()
{
	scanf("%d%d",&n,&m);
}

void Prime()
{
	int m=sqrt(MAXN+0.5);
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=MAXN;j+=i)
				vis[j]=1;
	for(int i=2;i<MAXN;i++)
		if(!vis[i])
			p[++l]=i;
}

void mul(int x)
{
	for(int i=1;i<=9593 && x!=1;i++)
        while(x%p[i]==0) 
        	cnt[i]++,x/=p[i];
}

void chu(int x)
{
	for(int i=1;i<=9593 && x!=1;i++)
        while(x%p[i]==0) 
        	cnt[i]--,x/=p[i];
}

void work()
{
	for(int i=n;i>=n-m+1;i--)
		mul(i);
	for(int i=m;i>=1;i--)
		chu(i);
	for(int i=1;i<=9593;i++) 
		if(cnt[i]) 
			ans++;
	cout<<ans<<endl;
}

int main()
{
	init();
	Prime();
	work();
}
     