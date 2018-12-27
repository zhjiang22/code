/*
做这题是在做比赛题目的时候，
看到这题数据范围，看到n这么大，直接哭了出来
然后就去看后面的题目了
果然我太弱了瞬间发现后面的也不会
然后一路暴力回来
突然脑子一动233333
发现如果计算的n,m
n比m会更大，那么计算到m!,(m+1)!,(m+2)!的时候
一取模就没了啊
因为里面已经含有了m这个因子
所以余数一定是0
就可以不用考虑
然后就用的是对1到min(n,m)计算阶乘然后相加
发现诶不对这个复杂度明显超时啊
100万的范围估计就是O(n)？
突然发现自己傻逼了
我们计算1到min(n,m)的阶乘的时候
比如计算i的阶乘，那么i+1的阶乘就可以不用直接算了
就直接在保留的i的阶乘上乘上一个i+1就好了
以此类推
好像是一个很简单的技巧只能说做题目太少了
不过还好是想出来了
注意n和m还有循环体中的i一定要开到long long 
不然就爆了。。。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

long long n,m;
int sum=1,ans;

int main()
{
	cin>>n>>m;
	for (long long i=1;i<=min(n,m);i++)
	{
		sum=(i*sum)%m;
		ans=(ans+sum)%m;
	}
	cout<<ans%m<<endl;
	return 0;
}
     