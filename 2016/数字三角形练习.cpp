#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
int f[502][502];
int a[502][502];
int n;

int main()
{
	 memset(f,0,sizeof(f));
	 cin>>n;
	 for(int i=1;i<=n;i++)
	 	for(int j=1;j<=i;j++)
	 		cin>>a[i][j];
	 for(int i=1;i<=n;i++)
	 	f[n][i]=a[n][i];
	 for(int i=n-1;i>=1;i--)
	 	for(int j=n-1;j>=1;j--)
	 		f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
	 cout<<f[1][1]<<endl;
	 return 0;
}
     