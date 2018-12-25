#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int p[MAXN];
int w[MAXN];
int f[MAXN];
int n,k,t,ans;

void init()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>w[i],f[i]=w[i];
	ans=0;
}

void DP()
{
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(p[i]-p[j]>k)
				f[i]=max(f[i],f[j]+w[i]);
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]);
	cout<<ans<<endl;	
}

int main()
{
	cin>>t;
	while(t--)
	{
		init();
		DP();
	}
	return 0;
}
     