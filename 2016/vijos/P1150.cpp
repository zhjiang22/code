/*
经典好题~一个dp必学题叭~~
首先我们要想怎么样才能完整表示一个状态~
我们可以看到的
如果去关灯关掉了区间[l,r]的灯
那么最后关的一盏不是l就是r
所以我们可以想到用这样一个状态表示
f[l][r][k]表示关掉区间[l,r]的所有灯所需要的最小代价
其中k=0表示现在人在l即最后关的灯是l
k=1表示现在人在r即最后关的是r这盏灯
这样就设计出了一个正确无误的状态
先考虑初值
f[i][i]就是从起始位置直接到i开i灯的代价
那么我们来考虑状态转移
我们知道f[l][r][0]表示的是最后关掉了l这盏灯使得[l,r]全部都关了
那么对应的上一个状态必然是已经关掉了[l+1,r]区间所有的灯
那么我们就要考虑到到底是f[l+1][r][0]转移过来更优还是f[l+1][r][1]更优
即考虑到了左右两种完全的情况
那么很容易有状态转移
f[i][j][0]=min(f[i+1][j][0]+(sump-(s[i+1][j]))*getd(i,i+1),
			   f[i+1][j][1]+(sump-(s[i+1][j]))*getd(i,j));
其中我们已经预处理出sump表示所有灯总功率
s[i]表示1...i的所有灯的功率然后用前缀和可以算出s[i+1][j]
这个转移仔细理解一下就好了
同理就可以得出f[i][j][1]的转移
递推的时候外层循环枚举长度内层循环枚举起点
最后取f[1][n][0]和f[1][n][1]的更优值就好了~
时间复杂度O(n^2)
可以直接秒杀~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=52;
int f[MAXN][MAXN][2];
int d[MAXN];
int s[MAXN];
int sump;
int n,poss;

void init()
{
	int p;
	scanf("%d%d",&n,&poss);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&d[i],&p);
		s[i]=s[i-1]+p;	sump+=p;
	}
}

inline int getd(int x,int y)
{
	return abs(d[x]-d[y]);
}

void DP()
{
	memset(f,0x37,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][i][0]=f[i][i][1]=abs(d[i]-d[poss])*sump;
	for(int l=2;l<=n;l++)
		for(int i=1;i<=n&&i<=n-l+1;i++)
		{
			int j=i+l-1;
			f[i][j][0]=min(f[i+1][j][0]+(sump-(s[j]-s[i]))*getd(i,i+1),
						   f[i+1][j][1]+(sump-(s[j]-s[i]))*getd(i,j));
			f[i][j][1]=min(f[i][j-1][0]+(sump-(s[j-1]-s[i-1]))*getd(i,j),
						   f[i][j-1][1]+(sump-(s[j-1]-s[i-1]))*getd(j-1,j));
		}
	cout<<min(f[1][n][0],f[1][n][1])<<endl;
}

int main()
{
	init();
	DP();
}