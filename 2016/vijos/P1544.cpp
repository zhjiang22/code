/*
一道明显的0/1背包咯~
OTZ其实就是一个二位费用的背包同时维护一个最小时间就是了
那么我们可以另开一个g[i][j]
表示对应的f[i][j]所要花费的时间
那么更新的时候要以f[][]为第一关键词
相同时再以g[][]为比较方式
然后一遍0/1背包记录一下最优解就好了~
还是不难的
注意一下细节就好了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int INF=(1<<30)-1;
struct node
{
	int rmb,rp,times;
}a[MAXN];
int f[MAXN][MAXN];//f[j][k]花了jrmb花了krp可以得到的最多GF
int g[MAXN][MAXN];//对应f[j][k]需要的最少时间
int n,M,R;
int anst=INF,ansf=-INF;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].rmb>>a[i].rp>>a[i].times;
	cin>>M>>R;
}

int main()
{
	init();
	for(int k=1;k<=n;k++)
		for(int i=M;i>=a[k].rmb;i--)
			for(int j=R;j>=a[k].rp;j--)
				if(f[i][j]<f[i-a[k].rmb][j-a[k].rp]+1||(f[i][j]==f[i-a[k].rmb][j-a[k].rp]+1&&g[i][j]>g[i-a[k].rmb][j-a[k].rp]+a[k].times))
				{
					f[i][j]=f[i-a[k].rmb][j-a[k].rp]+1;
					g[i][j]=g[i-a[k].rmb][j-a[k].rp]+a[k].times;
					if(f[i][j]>ansf||(f[i][j]==ansf&&g[i][j]<anst))
					{
						ansf=f[i][j];
						anst=g[i][j];

					}
				}
	cout<<anst<<endl;
	return 0;
}
     