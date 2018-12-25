#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int a[MAXN];
int f[MAXN];
int ans;
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		f[i]=a[i];
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[j]<a[i])
				f[i]=max(f[i],f[j]+a[i]);
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}
     