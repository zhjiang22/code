/*
第一眼以为是无脑搜索
后面才知道原来是小学奥数Orz
结果就是
把数n尽可能拆成最多的3
这样乘积会最大
那么如果当前n正好是3的整数倍
自然就是直接拆成n/3个3相乘最优了
如果n%3==1
那么如果拆成n/3个3和一个1相乘不是最优的
而是应该将一个3和那个1组合成一个4很明显比上面的更优
如果是n%3==2
那么拆分成n/3个3然后剩下一个2直接乘进去就好了
注意数据范围很大需要用到高精度
唉高精度写的心好累啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int Base=10;
struct bign
{
	int num[500],len;
	bign(int x=1,int len1=1)
	{
		memset(num,0,sizeof(num));
		num[1]=x;
		len=len1;
	}
	bign bei(int x)
	{
		bign c(0,len+1);
		for(int i=1;i<=len;i++)
		{
			c.num[i]+=num[i]*x;
			if(c.num[i]>=Base)
			{
				c.num[i+1]+=c.num[i]/Base;
				c.num[i]%=Base;
			}
		}
		while(!c.num[c.len])
			c.len--;
		return c;
	}
};
int n;

int main()
{
	scanf("%d",&n);
	if(n<=3)
	{
		cout<<n<<endl;
		return 0;
	}
	bign x(3,1);
	if(n%3==0)
	{
		for(int i=1;i<n/3;i++)
			x=x.bei(3);
	}
	else	if(n%3==1)
	{
		for(int i=1;i<(n/3-1);i++)
			x=x.bei(3);
		x=x.bei(4);
	}
	else
	{
		for(int i=1;i<n/3;i++)
			x=x.bei(3);
		x=x.bei(2);
	}
	for(int i=x.len;i>=1;i--)
		cout<<x.num[i];
	cout<<endl;
	return 0;
}
     