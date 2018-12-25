#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=305;
int s[MAXN][MAXN];
int f[MAXN][MAXN];//f[i][j]表示前i个村庄建j个邮局的最小代价
int a[MAXN];
int n,m;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
				s[i][j]=s[i][j-1]+a[j]-a[(i+j)/2];
	memset(f,0x3f,sizeof(f));
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		f[i][1]=s[1][i];
	for(int j=2;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
			for(int k=1;k<i;k++)
				f[i][j]=min(f[i][j],f[k][j-1]+s[k+1][i]);
	}
	cout<<f[n][m]<<endl;
	return 0;
}
     