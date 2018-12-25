#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long a[100][100],d[100][100]={0};
unsigned long long n;


int main()
{
	cin>>n;
	for(unsigned long long i=1;i<=n;i++)
		for(unsigned long long j=1;j<=i;j++)
		cin>>a[i][j];
	for(unsigned long long i=1;i<=n;i++)
	d[n][i]=a[n][i];
	for(unsigned long long i=n-1;i>=1;i--)
		for(unsigned long long j=1;j<=n;j++)
		d[i][j]=max(d[i+1][j],d[i+1][j+1])+a[i][j];
	cout<<d[1][1]<<endl;
	return 0;
}
