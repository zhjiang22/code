#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int INF=0xffffff;
int a[26][26];
int f[26][26];
int n;
int x,y;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>a[i][j];
	cin>>x>>y;
	a[x][y]+=INF;
	for(int i=n;i>=1;i--)
		for(int j=1;j<=i;j++)
			f[i][j]=max(f[i+1][j+1],f[i+1][j])+a[i][j];
	cout<<f[1][1]-INF<<endl;
	system("pause");
	return 0;
}
     