#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int f[MAXN];
int a[MAXN];
int n;
int T;
int ans;

int main()
{
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			f[i]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
				if(a[i]>a[j])
					f[i]=max(f[i],f[j]+1);
			ans=max(ans,f[i]);
		}
		for(int i=1;i<=n;i++)
			f[i]=1;
		for(int i=n;i>=1;i--)
		{
			for(int j=n;j>i;j--)
				if(a[i]>a[j])
					f[i]=max(f[i],f[j]+1);
			ans=max(ans,f[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
     