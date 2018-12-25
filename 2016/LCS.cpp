#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int f[2][100002];
int a[100002],b[100002];
int n1,n2;

int main()
{
	cin>>n1>>n2;
	for(int i=1;i<=n1;i++)
		cin>>a[i];
	for(int j=1;j<=n2;j++)
		cin>>b[j];

	for(int i=1;i<=n1;i++)
		for(int j=1;j<=n2;j++)
			{
				if(a[i%2]==b[j])
					f[i%2][j]=f[(i-1)%2][j-1]+1;
				else
					f[i%2][j]=max(f[(i-1)%2][j],f[i%2][j-1]);
			}
	cout<<f[n1%2][n2];
	system("pause");
	return 0;
}