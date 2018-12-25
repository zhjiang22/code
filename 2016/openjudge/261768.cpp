#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int a[MAXN][MAXN];
int s[MAXN][MAXN];
int ans;
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			s[i][j]=s[i][j-1]+a[i][j];
		}
	}
	ans=a[1][1];
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int x=0;
			for(int k=1;k<=n;k++)
			{
				x+=s[k][j]-s[k][i-1];
				if(x<0)
					x=0;
				ans=max(ans,x);
			}
		}
	cout<<ans<<endl;
	return 0;
}
     