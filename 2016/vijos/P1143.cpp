/*
经典问题，f[x][i][j][k]表示第x步三个人分别在第i行，第j行，第k行时所能达到最大值，
i,j,k顺推逆推皆可，因为用到的是f[x-1][][][]；
初值为f[1][1][1][1]=a[1][1]；
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int f[41][21][21][21];
int n;
int a[22][22];

int max1(int a,int b,int c,int d,int f,int g,int h,int i)
{
	int ans;
	ans=max(a,b);
	ans=max(ans,c);
	ans=max(ans,d);
	ans=max(ans,f);
	ans=max(ans,h);
	ans=max(ans,i);
	ans=max(ans,g);
	return ans;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	f[1][1][1][1]=a[1][1];
	for(int x=1;x<=2*n-1;x++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
				{
					int i1=x-i+1;int j1=x-j+1;int k1=x-k+1;
					if(i1<0||j1<0||k1<0)	continue;
					f[x][i][j][k]=max1(f[x-1][i-1][j][k],f[x-1][i][j-1][k],
									  f[x-1][i][j][k-1],f[x-1][i-1][j-1][k],
									  f[x-1][i-1][j][k-1],f[x-1][i][j-1][k-1],
									  f[x-1][i-1][j-1][k-1],f[x-1][i][j][k])+a[i][i1]+a[j][j1]+a[k][k1];//最后一个状态别忘了x也要-1
					if(i==j)
						f[x][i][j][k]-=a[i][i1];
					if(j==k)
						f[x][i][j][k]-=a[j][j1];
					if(i==k)
						f[x][i][j][k]-=a[i][i1];
					if(i==k&&k==j)
						f[x][i][j][k]+=a[i][i1];
				}
	cout<<f[2*n-1][n][n][n]<<endl;
	return 0;
}
     