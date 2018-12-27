/*
哈~一个挺简单的dp的直接就A了
状态应该很好想到
f[i][j]表示当前签证到第i层的第j个房间需要的最小费用
那么一个f[i][j]有三个决策
f[i-1][j],f[i][j-1],f[i][j+1]三个状态转移而来
注意因为同时存在f[i][j-1]和f[i][j+1]
所以在第二维的方向上注定不能一次推出来
应该是先从左往右推一次再从右往左推一次~
这样才能具有无后效性和最优子结构性质了~
那么我们递推出f[][]之后
就找到f[m][]中的最小值
即最后所在的位置(m,p)
那么开始递归打印路线
我们可以很容易通过f[][]来判断当前状态是由哪个状态转移而来
那么我们先递归打印下去
递归边界就是f[1][]的时候直接输出当前坐标就可以return了
在递归结束后才输出自己的坐标
就可以轻松AC~！
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=505;
const int MAXM=105;
const int INF=(1<<30)-1;
int f[MAXM][MAXN];
int w[MAXM][MAXN];
int n,m;
int ans=INF,p;

void init()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&w[i][j]);
	memset(f,0x3f,sizeof(f));
}

void DP()
{
	for(int i=1;i<=n;i++)
		f[1][i]=w[1][i];
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			f[i][j]=f[i-1][j]+w[i][j];
		for(int j=2;j<=n;j++)
			f[i][j]=min(f[i][j],f[i][j-1]+w[i][j]);
		for(int j=n-1;j>=1;j--)
			f[i][j]=min(f[i][j],f[i][j+1]+w[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		if(f[m][i]<ans)
		{
			ans=f[m][i];
			p=i;
		}
	}
}

void print(int x,int y)
{
	if(x==1)
	{
		cout<<y<<endl;
		return;
	}
	if(f[x-1][y]+w[x][y]==f[x][y])
		print(x-1,y);
	else	if(f[x][y-1]+w[x][y]==f[x][y])
		print(x,y-1);
	else
		print(x,y+1);
	cout<<y<<endl;
}

int main()
{
	init();
	DP();
	print(m,p);
}
     