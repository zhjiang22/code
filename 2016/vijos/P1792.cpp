/*
题目没有给清楚数据范围
0<n≤100，0<m≤100，0≤ai≤100
OTZ
又是一个0/1变形了
我们来看这个题目
注意这句话
{
摆花时同一种花放在一起,且不同种类的花需按标号的从小到大的顺序依次摆列
}
其实这句话的价值就在于告诉了我们
选择方案与选择的顺序是无关的
就像是一个排列OTZ?
然后我们就可以发现
我们的每一种花都有选择0..1..2..a[i]种的情况
这就转换成了一个多重背包？
然而发现每个没有权值啊
所以就直接乱写就好了
按照0/1的思路来
一开始定义状态f[i][j]表示选到第i种花已经选了j朵的方案
那么状态转移方程就是
f[i][j]=(f[i][j]+f[i-1][j-k])%1000007;
其中k要是0-a[i]
然后我们还是用0/1的一维优化咯
定义f[j]表示已经选了j朵的方案
转移方程就是
f[j]=(f[j]+f[j-k])%1000007;
也是要逆推
再加上一句枚举每个物品选多少件的循环
O(n^3)
其实也就是一个朴素的多重背包OTZ
裸的啊
果然我还是太弱惹Orz
两个版本都在下面咯
可以直接秒杀无压力
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int f[MAXN];
int n,m;
int x;

int main()
{
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=m;j>=1;j--)
			for(int k=1;k<=min(x,j);k++)
				f[j]=(f[j]+f[j-k])%1000007;
	}
	cout<<f[m]<<endl;
}

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int f[MAXN][MAXN];
int n,m;

int main()
{
	int x;
	cin>>n>>m;
	cin>>x;
	for(int i=0;i<=x;i++)
		f[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		for(int j=0;j<=m;j++)
			for(int k=0;k<=x;k++)
				if(j>=k)
					f[i][j]=(f[i][j]+f[i-1][j-k])%1000007;
	}
	cout<<f[n][m]<<endl;
	return 0;
}
*/
