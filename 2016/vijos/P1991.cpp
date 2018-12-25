/*
好题啊~但是好像有点重了
原先做过一个一样的题目
都是两端取数的题目
果然做过了就是熟练三下五除二写了出来
看到n=10000心悬了一下
O(n^2)会挂啊
抱着试试的感觉交了一下
然后AC了最大时间是1300ms
然后仔细一看才发现竟然是3ms的时间OTZ
我们定义f[i][j]表示[i,j]这个区间所能取到的最大值
那么初值自然是f[i][i]=a[i]
然后预处理s[i]表示[1,i]的总和
然后状态转移方程很明显就是
f[i][j]=(s[j]-s[i-1])-min(f[i+1][j],f[i][j-1]);
即拿完这一次下一次就是别人拿了
要让别人拿的更少	剩下的就是你的了
因为每次递推f[i][j]用到的既有f[i+1][j]又有f[i][j-1]
那么我们的递推顺序必然要换个思路了
我们看到递推一个f[i][j]要用到比它区间长度少一的区间的f[][]
所以我们可以直接第一维按照区间长度递推
第二维枚举起点
这样就可以把终点算出来了~
然后直接水了出来
复杂度O(N^2)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
int f[MAXN][MAXN];
int s[MAXN];
int a[MAXN];
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
		f[i][i]=a[i];
}

int main()
{
	init();
	for(int l=1;l<=n-1;l++)
		for(int i=1;i<=(n-l);i++)
		{
			int j=i+l;
			f[i][j]=(s[j]-s[i-1])-min(f[i+1][j],f[i][j-1]);
		}
	cout<<f[1][n]<<endl;
}
     