#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=30;
int f[MAXN][2];
int n;

int main()
{
	cin>>n;
	f[1][0]=1;
	f[2][1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i][0]+=f[i-1][0]+f[i-1][1];
		f[i][1]+=f[i-2][0]+f[i-2][1];
	}
	cout<<f[n][0]+f[n][1]<<endl;
	return 0;
}
     