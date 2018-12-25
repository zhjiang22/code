/*
超经典的双向LIS~
我们可以考虑到
我们求解LIS是定义f[i]表示前i个人的最长LIS
那么我们实际要求的是一个正向LIS拼上一个反向LIS的最大值
这个题目的核心就是选取一个中间人
那个转折点
所以我们可以枚举这个中间人
然后看哪个人作为中间人最优QAQ
首先想法是枚举中间人位置，然后左右求LIS，O(N^3)对于n<101的数据可过。
考虑到中间人不受LIS的影响，故只需正反两遍LIS，再枚举中间人位置，可降为
O(N^2)
所以我们从前向后先做一次正向LIS
求出所有的前i个人的最大LIS
然后从后向前做一次LIS(从前向后做最长下降也可以)
注意求出来之后i一定要在序列中
然后就可以得出所有的f1[i],f2[i]
其中f1[i]表示正向的前i个人的LIS
f2[i]表示反向的前i个人的LIS
那么我们就枚举所有中间点
选取最大的f1[i]+f2[i]即可
注意到因为这样会算重复中间那个人
所以-1就好了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[105];
int f1[105];
int f2[105];
int n;
int ans;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f1[i]=f2[i]=1;
	}
}

void LIS()
{
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[i]>a[j])
				f1[i]=max(f1[i],f1[j]+1);
	for(int i=n-1;i>=1;i--)
		for(int j=n;j>i;j--)
			if(a[i]>a[j])
				f2[i]=max(f2[i],f2[j]+1);
}

void out()
{
	for(int i=1;i<=n;i++)
		ans=max(ans,f1[i]+f2[i]-1);
	printf("%d\n",n-ans);
}

int main()
{
	init();
	LIS();	
	out();
}
     