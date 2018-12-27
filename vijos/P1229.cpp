/*
一道入门枚举水题了~
看到超过2万就直接输出无解就知道直接枚举是可以的
一共一万个数字
在判断有多少个正因子的时候
可以直接试到sqrt(x)也可以直接试到x(虽然慢了但是是可行的)
主要要特殊判断一下
如果x正好是一个完全平方数
那么返回的数量就应该是tot*2-1(sqrt(x)不能算两次)
如果不是的话自然就是sqrt(x)*2了
这道是入门题了
有个dfs加强版咯P1310推荐做一下~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxw=20000;
int k;

int work(int x)
{
	int c=sqrt(x)+0.5;
	int tot=0;
	for(int i=1;i<=c;i++)
		if(x%i==0)
			tot++;
	if(c*c==x)
		return (tot<<1)-1;
	else
		return tot<<1;
}

int main()
{
	cin>>k;
	for(int i=1;i<=maxw;i++)
	{
		if(work(i)==k)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"NO SOLUTION"<<endl;
	return 0;
}
     