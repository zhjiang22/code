/*
强啊~
还要啥dfs构造真是太弱惹
窝们可以直接暴力啊
暴力出奇迹~！
首先我们都知道的
任何一个偶数位的回文数
一定能被11整除~！(百度有证明的)
那么我们只需要判断奇数位数的回文数就好了
那么检查的范围小了很多
而且我们看到
数据范围n,m是到了100000000(一个亿)
但是我们并不需要搜到一个亿啊
我们知道偶数位数的回文数必然是不满足的
那么我们只需要搜到一千万之内就行了~!
那么就是直接把r改成min(r,10000000)
然后可以开始写check了
对于一个x
如果x的个位数是偶数的话
必然是不可能是素数的
那就直接return 0就好了
其次如果发现位数是偶数位
剪枝
然后判断一下是不是回文数
最后判断是不是素数(到sqrt)
注意我们这里是从运算量小到大
这样可以大大提高效率
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int l,r;
int a[10];

bool check(int x)
{
	if(x<=2)
		return 0;
	int len=0,last=x%10;
	memset(a,0,sizeof(a));
	if(last==2||last==4||last==6||last==8||last==0)
		return 0;
	int q=x;
	while(q)
	{
		a[++len]=q%10;
		q/=10;
	}
	if(!len%2) 
		return false;
	for(int i=1;i<=(len>>1);i++)
		if(a[i]!=a[len-i+1])
			return 0;
	int k=sqrt(x)+0.5;
	for(int i=2;i<=k;i++)
		if(x%i==0)
			return 0;
	return 1;
}

int main()
{
	cin>>l>>r;
	r=min(r,10000000);
	for(int i=l;i<=r;i++)
		if(check(i))
			printf("%d\n",i);
	return 0;
}
     