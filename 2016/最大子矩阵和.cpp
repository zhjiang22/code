#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int ans=-9999999;
int tot;
int a[502][502];
int sum[502][502];
int f[502];
int n,m;

int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum[i][j]=sum[i-1][j]+a[i][j];
	for(int i=0;i<=n;i++)//从0开始
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
				f[k]=sum[j][k]-sum[i][k];
			int tot=0;
			for(int k=1;k<=m;k++)
			{
				tot+=f[k];
				if(tot>ans)
					ans=tot;
				if(tot<0)
					tot=0;
			}
		}
	}
	cout<<ans<<endl;
	system("pause");
	return 0;
}
     