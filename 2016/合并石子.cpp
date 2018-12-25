#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int f[100][100];
int n;
int sum[100];
int x;

int main()
{
	cin>>n;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=n;i++)
		cin>>x,sum[i]=sum[i-1]+x;
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<j;k++)
				f[i][j]=min(f[i][k]+f[k+1][j],f[i][j])+(sum[j]-sum[i-1]);
	cout<<f[1][n]<<endl;
	system("pause");
	return 0;
}
     