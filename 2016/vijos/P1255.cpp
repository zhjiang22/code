/*
一个傻逼题啊OTZ
竟然被吓得不敢做原来
其实就是一个最大子矩阵裸题Orz
不过就是设置了几个点不能选
而我们对于不能选的点
就全部设置为-INF
这样就肯定不会选上了
我们看到n和m是同等级大小的
所以枚举行和列都是差不多一样的
所以我们可以用i,j来枚举所有的列
就像是两个指针在这里夹着扫描
然后用k来枚举所有的行
预处理s[i][j]表示第i行前j个数的和
就用上了最长连续子序列和
这样直接就变成裸题了
随便乱搞就好了
唉本来想写个极大化的
但是发现并不需要辣么麻烦就随便乱写了一个咯
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1010;
const long long INF=0x7fffffff;
long long a[MAXN][MAXN];
long long s[MAXN][MAXN];
int n,m;
long long sum,ans,d;

inline long long delta(int k,int x,int y)
{
	return s[k][y]-s[k][x-1];
}

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
				a[i][j]=-INF;
			s[i][j]=s[i][j-1]+a[i][j];
		}
}

int main()
{
	init();
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
		{
			sum=0;
			for(int k=1;k<=n;k++)
			{
				sum+=delta(k,i,j);
				if(ans<sum)
					ans=sum;
				else	if(sum<0)
					sum=0;
			}
		}
	cout<<ans<<endl;
	return 0;
}
     