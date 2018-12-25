#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=25;
int f[MAXN][2];
int n;

int main()
{
	cin>>n;
	f[1][0]=1;
	f[2][1]=1;
	f[2][0]=1;
	for(int i=3;i<=n;i++)
	{
		f[i][1]=f[i-2][1]+f[i-2][0];
		f[i][0]=f[i-1][1]+f[i-1][0];
	}
	cout<<f[n][1]+f[n][0]<<endl;
	return 0;
}
     