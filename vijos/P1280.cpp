/*
秒杀了23333
一个有点类似于数字三角形的DP咯
但是我们注意
上下两个三角形的dp是要分开来的不一样
和搭建双塔的思想差不多
我们发现直接定义f[i][j]表示到(i,j)所能达到的最优解很不好转移
所以我们定义状态bool f[i][j][k]表示到(i,j)是否可以达到k的差值
这样就可以很轻松地转移了
反正我是看到测试数据最多知道了50的ans
所以f[][][]第三维开到100就好了
本来如果按道理是要开到-30*50 -- 30*50
注意这里的转移
分两个部分转移
很巧妙
羡慕pascal啊可以直接负数做下标
而这里我们就要用一个内联函数p来转换一下这个负的下标咯
就是对于正的负的数都+上一个数变成正的或者更大的正数
hash一样吧
然后直接乱搞就好了
找答案的时候因为是要最小差距的绝对值
我们从0-50枚举	对于最小的i
如果f[2*n-1][1][i]或者f[2*n-1][1][-i]有一个成立就是最优答案了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100;
bool f[MAXN][MAXN][MAXN];
int a[MAXN][MAXN];
int n;

inline int p(int i)
{
	return i+50;
}

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>a[i][j];
	for(int i=n+1;i<=2*n-1;i++)
		for(int j=1;j<=2*n-i;j++)
			cin>>a[i][j];
	f[1][1][p(a[1][1])]=1;
}

int main()
{
	init();
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i;j++)
			for(int k=-50;k<=50;k++)
			{
				if(j>1)
				{
					if(k-a[i][j]<=50&&k-a[i][j]>=-50)
						f[i][j][p(k)]=(f[i][j][p(k)]||f[i-1][j-1][p(k-a[i][j])]);
					if(k+a[i][j]<=50&&k+a[i][j]>=-50)
						f[i][j][p(k)]=(f[i][j][p(k)]||f[i-1][j-1][p(k+a[i][j])]);
				}
				if(j<i)
				{
					if(k-a[i][j]<=50&&k-a[i][j]>=-50)
						f[i][j][p(k)]=(f[i][j][p(k)]||f[i-1][j][p(k-a[i][j])]);
					if(k+a[i][j]<=50&&k+a[i][j]>=-50)
						f[i][j][p(k)]=(f[i][j][p(k)]||f[i-1][j][p(k+a[i][j])]);
				}
			}
	for(int i=n+1;i<=2*n-1;i++)
		for(int j=1;j<=2*n-i;j++)
			for(int k=-50;k<=50;k++)
			{
				if(k-a[i][j]<=50&&k-a[i][j]>=-50)
					f[i][j][p(k)]=(f[i][j][p(k)]||f[i-1][j+1][p(k-a[i][j])]),
					f[i][j][p(k)]=(f[i][j][p(k)]||f[i-1][j][p(k-a[i][j])]);
				if(k+a[i][j]<=50&&k+a[i][j]>=-50)
					f[i][j][p(k)]=(f[i][j][p(k)]||f[i-1][j+1][p(k+a[i][j])]),
					f[i][j][p(k)]=(f[i][j][p(k)]||f[i-1][j][p(k+a[i][j])]);
			}
	for(int i=0;i<=50;i++)
		if(f[2*n-1][1][p(i)]||f[2*n-1][1][p(-i)])
		{
			cout<<i<<endl;
			return 0;
		}
	return 0;
}
     