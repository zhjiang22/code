/*
一道很巧妙的题目呀~
竟然是没有想到
一开始一直想着一种新的dp方法发现推不下去了
然后看了下题解
看到个LCS的字眼瞬间就啥都懂了
这道题是有另外一种dp做法的
但是如果转换为LCS来做肯定就是更方便简单了
毕竟还是写自己最熟悉的算法最保险~>3<
我们可以这样搞
对于当前字串a	我们把他倒过来
因为是要一个回文串
所以肯定就是要保证更多的不变
那么有多少可以不变呢？
自然就是当前串和倒过来的串的公共子串了
因为我们要让加入的最少
所以我们就可以直接求一个最长的公共子串即可
犯了一个很傻的错误(雾
窝竟然以为string可以直接无限加ORZ
就直接把b也开始成了string类
然后没有指定大小
RE了两波后面手调了两下才发现
害羞~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=6005;
string a;
char b[MAXN];
int f[MAXN][MAXN];
int n;

void init()
{
	cin>>n;
	cin>>a;
	for(int i=0;i<n;i++)
		b[i]=a[n-i-1];
}

void LCS()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i-1]==b[j-1])
				f[i][j]=f[i-1][j-1]+1;
			else
				f[i][j]=max(f[i-1][j],f[i][j-1]);
	cout<<n-f[n][n]<<endl;
}

int main()
{
	init();
	LCS();
	return 0;
}
     