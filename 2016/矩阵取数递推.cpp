#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a[502][502];
int n;
int f[502][502];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		f[i][1]=a[i][1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
	cout<<f[n][n]<<endl;
	system("pause");
	return 0;
}
     