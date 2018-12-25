#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int INF=0x7fffff;
int x;
int sum[102];
int f[102][102];
int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x,sum[i]=sum[i-1]+x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=INF;
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i;k<=j-1;k++)//k>i,所以决定了一维顺序应是从大到小推
			 	f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+(sum[j]-sum[i-1]));//
		}
	cout<<f[1][n]<<endl;	
	return 0;
}
     