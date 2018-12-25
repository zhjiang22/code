#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int a[MAXN][MAXN];
int f[MAXN][MAXN];
int n,m;
int ans;

void init()
{
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=1;
	}
}

void DP()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!a[i][j])
			{
				f[i][j]=1;
				f[i][j]=max(f[i][j],min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1);
				ans=max(ans,f[i][j]);
			}
	printf("%d\n",ans);
}

int main()
{
	init();
	DP();
}
     