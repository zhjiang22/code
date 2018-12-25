#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int a[102];
int f[102][10000];
int sum=0;
int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=(sum/2);j++)
			if(a[i]>j)
				f[i][j]=f[i-1][j];
			else
				f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+a[i]);
	}
	cout<<sum-2*f[n][sum/2];
	return 0;
}