/*
水题啊
就是个高精度阶乘Orz
因为n>=3时，n!中必定带有因子3，
所以各位数加起来还是有因子3，一定不是素数，只要特判n=2即可
这个结论很奇妙了
所以我们只要求高精度阶乘
然后累加各位上的数就好咯~
QWQ
表示我太弱了高精度竟然都卡了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod=10000;
struct bign
{
	int a[mod],len;
	bign()
	{
		memset(a,0,sizeof(a));
		a[1]=1;
		len=1;
	}
	bign operator *(const int &b)
	{
		bign c;
		c.len=999;
		c.a[1]=0;
		for(int i=1;i<=len;i++)
		{
			c.a[i]+=b*a[i];
			if(c.a[i]>=mod)
			{
				c.a[i+1]+=(c.a[i]/mod);
				c.a[i]%=mod;
			}
		}
		while(c.a[c.len]==0)
			c.len--;
		return c;
	}
};
bign a;
int n;
int ans;

void out(bign x)
{
	for(int i=1;i<=x.len;i++)
	{
		int k=x.a[i];
		while(k)
		{
			ans+=k%10;
			k/=10;
		}
	}
	cout<<ans;
}

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
		a=a*i;
	out(a);
	if(n>2)
		cout<<'F';
	else
		cout<<'T';
	return 0;
}
     