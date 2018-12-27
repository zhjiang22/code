/*
好题~数据有点小就是
O(N^2)直接轻松水过~
很明显我们可以枚举区间起点和终点
然后计算出个数相加即可
我们看到枚举的复杂度是O(n^2)
计算也是O(n)那么总的复杂度是O(N^3)
5千的范围是承受不起的
自然会想到用一个前缀和去优化这个算法
让查询的时间降低到O(1)这样就可以在O(N^2)的时间内解决问题了
我们可以预处理s[i][j]表示从a[1]..a[2]..a[j]中比a[i]小的元素的个数
然后一个get(k,l,r)函数查询[l,r]中比a[k]小的数的个数
因为a...a[j-1]中的值只有3种情况，
要么比a[j]大，要么在a[i]与a[j]之间，要么比a[i]小。
比a[i]小的数，必然比a[j]小。所以用比a[j]小的数剪掉比a[i]小的数即可。
即有get(j,i+1,j)-get(i,i,j)
当然也可以用一些数据结构比如说主席树或者树状数组线段树来优化这个时间
让复杂度降到O(nlogn)
但是实际上O(n^2)对于这题的数据范围已经足够了
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=5005;
int s[MAXN][MAXN];
int a[MAXN];
long long ans;
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[j]<a[i])
				s[i][j]=s[i][j-1]+1;
			else
				s[i][j]=s[i][j-1];
}

inline int get(int k,int l,int r)//计算a[l]...a[r]中有多少个元素小于a[k]
{
	return s[k][r]-s[k][l-1];
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]<a[j])
				ans+=(get(j,i+1,j)-get(i,i,j));
	cout<<ans<<endl;
	return 0;
}
     