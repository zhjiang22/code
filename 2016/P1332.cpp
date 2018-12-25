#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=102;
const int INF=0x7ffffff;
int a[MAXN];
int b[MAXN];
int f[MAXN][MAXN][2];
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=0)
			b[i]=0;
		else	
		{
			b[i]=1;
			a[i]=-a[i];
		}
		f[i][i][0]=f[i][i][1]=a[i];
	}
}

void DP()
{
	for(int t=1;t<n;t++)
		for(int i=1;i<=n-1;i++)
		{
			int j=i+t;
			f[i][j][0]=-INF;
			f[i][j][1]=INF;
			for(int k=i+1;k<=j;k++)
			{
				if(b[k]==0)
				{
					f[i][j][0]=max(f[i][j][0],f[i][k-1][0]+f[k][k][0]);
					f[i][j][1]=min(f[i][j][1],f[i][k-1][1]+f[k][j][1]);
				}
				else
				{
					f[i][j][0]=max(f[i][j][0],f[i][k-1][0]-f[k][j][1]);
					f[i][j][1]=min(f[i][j][1],f[i][k-1][1]-f[k][j][0]);
				}
			}
		}
	cout<<f[1][n][0]<<endl;
}

int main()
{
	init();
	DP();
	return 0;
}
     