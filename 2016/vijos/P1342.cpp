/*
一道水dp?窝太弱了
我们可以看到这种有多少种方案的
其实就是递推啊...
恐怖
我们用f[i]表示到第i个数字有多少种解密方式
那么如果当前这个字符ch不为'0'
必然就是可以单独成为一种
那么就可以加上f[i-1]的方案数
但是我们考虑比如说
一个1和一个2其实是可以合起来当作一个12的
这样的翻译方案数是要增加f[i-2]
那么怎么样才可以增加呢？
必然就是
前面的不为0并且两个数合起来要在26之内咯
那么久直接O(n)递推就好啦
看到题解区好像说数据范围说是4100但是会更大
还好窝比较浪费f[]直接开到了5000
2333333
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=5000;
int f[MAXN];
int l;
string a;

void init()
{
	l=a.length();
	memset(f,0,sizeof(f));
}

void DP()
{
	init();
	f[0]=f[1]=1;
	int cur,last;
	for(int i=2;i<=l;i++)
	{
		cur=a[i-1]-'0';	last=a[i-2]-'0';
		if(cur!=0)
			f[i]+=f[i-1];
		if(last!=0&&last*10+cur<=26)
			f[i]+=f[i-2];
	}
	cout<<f[l]<<endl;
}

int main()
{
	while(cin>>a)
	{
		if(a=="0")
			break;
		else
			DP();
	}
	return 0;
}
     