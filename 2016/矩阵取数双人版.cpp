#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int INF=0x7fffff;
int n,m;
int a[205][205];
int f[405][205][205];

int max1(int a,int  b,int c,int d)
{
	int ans;
	ans=max(a,b);
	ans=max(ans,c);
	ans=max(ans,d);
	return ans;
}

int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	f[1][1][1]=a[1][1];
	for(int k=1;k<=n+m-1;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int i1=k-i+1;
				int j1=k-j+1;
				if(i1<0||j1<0)
					continue;
					f[k][i][j]=max1(f[k-1][i-1][j],f[k-1][i][j-1],f[k-1][i][j],f[k-1][i-1][j-1])+a[i][i1]+a[j][j1];
				if(i==j)
					f[k][i][j]
			}
		}
	}
	cout<<f[n+m-1][n][n]<<endl;
	system("pause");
	return 0;
}
     