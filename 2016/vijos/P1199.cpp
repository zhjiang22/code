#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

char a[10005][10005];
int n,m;

int main()
{
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n-m+1;i++)
		for(int j=1;j<=n-m+1;j++)
		{
			int tot=0;
			for(int q=i;q<=i+m-1;q++)
				for(int p=j;p<=j+m-1;p++)
					if(a[q][p]=='#')
						tot++;
			ans=max(ans,tot);
		}
	cout<<ans<<endl;
	return 0;
}
     