/*
挺裸的dp了~！
我们定义f[i]表示到第i个人为止需要的最少车数
很明显发现这道题目是具有最优子结构和无后效性的
那么这种划分型dp很容易想到就是找"断点"了
我们从0-i-1开始找到一个合适的断点j
如果j到i这些人可以在一辆车中就可以尝试转移
则有
f[0]=0;
f[i]=min(f[i],f[j]+1)(0=<j<i且can(j,i))
j到i这些人可以放在一辆车的条件是什么呢？
自然就是两种人的差值不超过D或者全是一个队的人~
那么就可以直接用一个数组s[i]记录前i个人的两个队的差值
即碰到一个J就+1 H就-1即可
判断的时候加上abs~
主要还要特判一下全是一个队的人~
一遍轻松AC!
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=2505;
int s[MAXN];
int f[MAXN];
int n,d;

void init()
{
	char ch;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>ch;
		if(ch=='J')
			s[i]=s[i-1]+1;
		else
			s[i]=s[i-1]-1;
	}
	memset(f,0x3f,sizeof(f));
}

int main()
{
	init();
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if(abs(s[i]-s[j])<=d||abs(s[i]-s[j])==i-j)
				f[i]=min(f[i],f[j]+1);
	cout<<f[n]<<endl;
	return 0;
}
     