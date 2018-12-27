/*
简单dp怎么人品这么高Orz
我好害怕
定义状态f[i][j][0]表示i到j段构成的的最大值
f[i][j][1]表示i到j段构成的最小值
对于读入的负数
我们可以先转换为正数	然后再用b[]数组记录是否转换过符号
那么我们枚举长度t从1到n-1
然后枚举起点i 从1到n-t
然后自然能计算出终点j
初始化时f[i][j][0]要设成极小数	f[i][j][1]极大数
我们枚举添加括号的断点k
自然是从i+1到j
如果b[k]==0
说明断的地方是个正数
则有
f[i][j][0]=max(f[i][j][0],f[i][k-1][0]+f[k][j][0]);
f[i][j][1]=min(f[i][j][1],f[i][k-1][1]+f[k][j][1]); 
(可以自己好好理解)
不然就是个负数
我们知道负数就是前面是个减号加个括号结果就反了一下
f[i][j][0]=max(f[i][j][0],f[i][k-1][0]-f[k][j][1]);
f[i][j][1]=min(f[i][j][1],f[i][k-1][1]-f[k][j][0]);
注意这里f[i][j][0]要取最大
那么f[k][j][]这一段肯定要取最小就是f[k][j][1]
同理下面这个也是
答案就是f[1][n][0]
自己好好想吧
挺简单哒
呼呼一天A了十道
放假了明天Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=102;
const int INF=0x7ffffff;
int a[MAXN];
int b[MAXN];
int f[MAXN][MAXN][2];
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=0)
			b[i]=0;
		else	
		{
			b[i]=1;
			a[i]=-a[i];
		}
		f[i][i][0]=f[i][i][1]=a[i];
	}
}

void DP()
{
	for(int t=1;t<n;t++)
		for(int i=1;i<=n-t;i++)
		{
			int j=i+t;
			f[i][j][0]=-INF;
			f[i][j][1]=INF;
			for(int k=i+1;k<=j;k++)
			{
				if(b[k]==0)
				{
					f[i][j][0]=max(f[i][j][0],f[i][k-1][0]+f[k][j][0]);
					f[i][j][1]=min(f[i][j][1],f[i][k-1][1]+f[k][j][1]);
				}
				else
				{
					f[i][j][0]=max(f[i][j][0],f[i][k-1][0]-f[k][j][1]);
					f[i][j][1]=min(f[i][j][1],f[i][k-1][1]-f[k][j][0]);
				}
			}
		}
	cout<<f[1][n][0]<<endl;
}

int main()
{
	init();
	DP();
	return 0;
}
     