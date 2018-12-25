#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long MAXN=30005;
long long f[MAXN];
long long n,m,k;

void init()
{
	scanf("%lld%lld%lld",&n,&m,&k);
}

int main()
{
	long long x,y;
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		for(int j=m;j>=x;j--)
			f[j]=max(f[j],f[j-x]+y);
	}
	long long ans=f[1];
	for(int i=2;i<=m;i++)
		ans=max(ans,f[i]);
	printf("%lld\n",k-ans);
	return 0;
}
     