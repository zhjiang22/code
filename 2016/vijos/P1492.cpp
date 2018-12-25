/*
Orz第一次写高精度bign
练习了一下
忘记初始化了233333
结果调了半天QAQ
写的好丑啊勿喷
毕竟我是个弱逼咯
高精度模板靠背都背下来吧
bign还是好用啊比手写强多了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXN=400;
const int mod=10000;
struct bign
{
	int a[MAXN];
	bign(int x=0)
	{
			memset(a,0,sizeof(a));
		if(!x)
		{
			a[0]=1;
		}
		else
		{
			int l=0;
			while(x)
			{
				a[++l]=x%mod;
				x/=mod;
			}
			a[0]=l;
		}
	}
	bign operator + (const bign b)
	{
		bign c;
		c.a[0]=max(a[0],b.a[0]);
		for(int i=1;i<=c.a[0];i++)
		{
			c.a[i]+=a[i]+b.a[i];
			if(c.a[i]>=mod)
			{
				c.a[i]-=mod;
				c.a[i+1]++;
			}
		}
		if(c.a[c.a[0]+1]>0)
			c.a[0]++;
		return c;
	}
}f[900];

ostream & operator << (ostream & o, bign &n)
{
	o<<n.a[n.a[0]];
	for (int i=n.a[0]-1;i>=1;i--)
	{
		o.width(4);
		o.fill('0');
		o<<n.a[i];
	}
	return o;
}


int main()
{	
	int n;
	bign a(1);
	bign b(2);
	swap(a,f[1]);
	swap(b,f[2]);
	cin>>n;
	for(int i=3;i<=n;i++)
	{
		bign x=f[i-1]+f[i-2];
		f[i]=f[i-2]+x;
		f[i].a[1]++;
	}
	cout<<f[n]<<endl;
	return 0;
}
     