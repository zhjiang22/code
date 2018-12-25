#include<string.h>
#include<algorithm>
#include <iostream>
#define maxn 502
int s[maxn][maxn];
using namespace std;
int n,j,k;
int add(int a[maxn][maxn])
{	 	
int i,j;
int d[maxn][maxn];
for(j=1;j<=n;j++)d[n][j]=a[n][j];
for(i=n;i>=1;i--)
for(j=n;j>=1;j--)
d[i][j]=a[i][j]+max(d[i+1][j],d[i][j+1]);
return d[1][1];
}
int main()
{
	int p;
	
	cin>>n;
	for(j=1;j<=n;j++)
	for(k=1;k<=n;k++)
	cin>>s[j][k];
	cout<<add(s);
	return 0;
}