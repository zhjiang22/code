#include<iostream>
#include<cstring>
using namespace std;
int a[100][100];
int f[100][100];
int n,m,x,y;

int main()
{
	memset(f,1,sizeof(f));
	memset(a,0,sizeof(a));
	cin>>n>>m>>x>>y;
	a[0][0]=1;
	f[x][y]=0,f[x+1][y+2]=0,f[x-1][y+2]=0;
    f[x+1][y-2]=0,f[x-1][y-2]=0,f[x+2][y+1]=0;
    f[x-2][y+1]=0,f[x+2][y-1]=0,f[x-2][y-1]=0;
	for(int i=1;i<=n;i++)
	if(f[i][0])
	a[i][0]=1;
	else break;	
	for(int i=1;i<=m;i++)
	if(f[0][i])
	a[0][i]=1;
	else break;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(f[i][j])
		a[i][j]=a[i-1][j]+a[i][j-1];
	cout<<a[n][m];
	return 0;
} 