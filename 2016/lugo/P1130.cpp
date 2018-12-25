#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int a[MAXN][MAXN<<1];
int f[MAXN<<1][MAXN];
int ans=0x7fffffff;
int n,m;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)
		f[1][i]=a[i][1];
}

int main()
{
	init();
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(j==1)
				f[i][j]=min(f[i-1][j],f[i-1][m])+a[j][i];
			else
				f[i][j]=min(f[i-1][j],f[i-1][j-1])+a[j][i];
		}
	for(int i=1;i<=m;i++)
		ans=min(ans,f[n][i]);
	cout<<ans<<endl;
	return 0;
}
     