/*
历年第一题签到题？	呵呵想了我半个多小时
我也是醉了
这是考数学吧卧槽？
Orz一直在想怎么周期乱搞	然后发现自己数学还是太弱了
就想到了直接拉成链吧
那么题目就变成了
给你n个人（0 - n-1）组成一个环，每次一起前进m步，问编号为x的人在移动了10 ^ k后，
他的位置是什么
还能说啥，假设我们把它拉成一个无限长的链，那么每m个长度就是一圈，
所以答案就是 (x + m * 10 ^ k) % n
然后一看这个k这么大	朴素O(n)肯定超时
肯定要用O(logn)快速幂算法
其实我不会告诉你	一开始我记错了
以为快速幂是O(nlogn)	2333333
然后一脸懵逼这怎么做啊2333
然后想想不对好像是O(logn)的样子
然后就果断打了个快速幂
然后用了我50分钟？
Orz我好弱啊QAQ
看别人的题解说一定要long long 不然30分？
一开始为了保险用了Long long
然后我用了int试了一下结果也AC了
66666666
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int n,m,k,x;
int p=10;
int ans=1;

void powder(int mod,int x)
{
	while(!(x&1))
	{
		p=p*p%mod;
		x>>=1;
	}
	ans=p%mod;
	x>>=1;
	while(x)
	{
		p=p*p%mod;
		if(x&1)
			ans=ans*p%mod;
		x>>=1;
	}
}

int main()
{
	cin>>n>>m>>k>>x;
	powder(n,k);
	cout<<((x+m*ans))%n<<endl;
	return 0;
}
     