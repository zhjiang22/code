/*
单调队列好题~！
我们很容易想到这样的状态表示
f[i]表示吃到第i个能量球能剩的最多能量~
那么很明显就是一个划分型dp的模型了
状态转移方程
f[i]=max(f[i],f[j]+s[i]-s[j]-100*i)(j<i&&f[j]>=100*i)
那么这样的复杂度是O(n^2)的了~
看到两百万的数据心好累
然后我们会发现
我们可以化简这个式子
f[i]=max{f[j]-s[j]}+s[i]-100*i
那么我们就是要找一个最大值了
很容易想到用单调队列优化了
每次维护这个可行区间(滑动窗口的最大值)(f[i]-s[i]的最值)
即对于每一个f[i]先删除当前队列队首的所有高度跳不到的元素
就是(窝比较喜欢用l和r代表头尾指针)
while(l<r&&f[q[l]]<i*100)
		l++
这样可以保证队首的元素就是可行的最值
算出f[i]后再将f[i]-s[i]作为元素值将i从尾部插入
并删除比它小的元素
就是
while(l<r&&gf(q[r])<gf(i))
		r++;
	q[r++]=i
那么很容易在O(n)的时间内算出f[n]了
初值是f[0]=m
然后就被vijos坑了一把O(n)在200万的数据华丽TLE
然后再交一次就550msAC惹~
总结一下咯~
有一些DP的状态转移是从之前的某些状态中取一个最值
那么它就有可能用单调队列来优化
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=2000005;
int f[MAXN];
int s[MAXN];
int q[MAXN];
int n,m;
int l,r;

void init()
{
	int x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s[i]=s[i-1]+x;
	}
}

inline int gf(int& i)
{
	return f[i]-s[i];
}

inline int get(int& i)
{
	while(l<r&&f[q[l]]<i*100)
		l++;
	return q[l];
}

inline void Push(int& i)
{
	while(l<r&&gf(q[r])<gf(i))
		r++;
	q[r++]=i;
}

void DP()
{
	f[0]=m;	q[r++]=0;
	for(int i=1;i<=n;i++)
	{
		int j=get(i);
		if(f[j]>=i*100)
			f[i]=max(f[i],f[j]+s[i]-s[j]-100*i);
		Push(i);
	}
	cout<<f[n]<<endl;
}

int main()
{
	init();
	DP();
}
     