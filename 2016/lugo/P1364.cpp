#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int g[MAXN][MAXN];
int a[MAXN];
int n;
int ans=0x7fffff;

void init()
{
	int x,y;
	memset(g,0x3f,sizeof(g));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		g[i][i]=0;
		cin>>a[i];
		cin>>x>>y;
		if(x!=0)
			g[x][i]=g[i][x]=1;
		if(y!=0)
			g[y][i]=g[i][y]=1;
	}
}

void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

void out()
{
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
			sum+=g[i][j]*a[j];
		ans=min(ans,sum);
	}	
	cout<<ans<<endl;
}

int main()
{
	init();
	Floyd();
	out();
	return 0;
}
     