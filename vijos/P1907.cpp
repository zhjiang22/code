#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXN=50;
struct node
{
	int x,y;
}a[MAXN];
int f[MAXN][MAXN];
int n,m,k;
int nowy,nowx;
int ans=0x7fffffff;

void init()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	nowx=1,nowy=m;
	memset(f,0x3f,sizeof(f));
}

int main()
{
	init();
	for(int i=1;i<=m;i++)
		f[0][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(j<a[i].y)
				f[i][j]=f[i-1][j+a[i].x]+1;
			else	if(j>=m-a[i].x)
				f[i][j]=f[i-1][j-a[i].y];
			else
				f[i][j]=min(f[i-1][j-a[i].y],f[i-1][j+a[i].x]+1);
		}
	for(int i=1;i<=m;i++)
		ans=min(ans,f[n][i]);
	cout<<ans<<endl;
	return 0;
}
     