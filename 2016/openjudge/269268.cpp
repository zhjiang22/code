#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=705;
int f[MAXN][3];
int a[MAXN];
int ans;
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[1][1]=a[1];
}

int main()
{
	init();
	for(int i=2;i<=n;i++)
		for(int j=0;j<4;j++)
		{
				if(j==0)
					f[i][j]=max(f[i-1][0],max(f[i-1][1],f[i-1][2]));
				else
					f[i][j]=max(f[i][j],f[i-1][j-1]+a[i]);
		}
	ans=max(f[n][0],f[n][1]);
	ans=max(ans,f[n][2]);
	cout<<ans<<endl;
	return 0;
}
     