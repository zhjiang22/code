/*
一个裸的数字三角形？
随便乱搞就好了
唯一的卖点就在于
题目有点隐晦啊
他的起点是在第n+1行的中点处
并不是第n行
注意到了这个就不用多说了
随便乱写都出来了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=205;
int a[MAXN][MAXN];
int f[MAXN][MAXN];
int n,m;
int fy;
int ans;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	fy=(m+1)/2;
	for(int i=1;i<=m;i++)
		f[1][i]=a[1][i];
}

int main()
{
	init();
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=max(f[i-1][j],max(f[i-1][j+1],f[i-1][j-1]))+a[i][j];
	ans=max(f[n][fy],max(f[n][fy-1],f[n][fy+1]));
	cout<<ans<<endl;
	return 0;
}
     