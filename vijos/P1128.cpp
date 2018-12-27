#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int a[24];
bool v[24];
long long f[25];
int n,k,ans;

bool check(int n)
{
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}

void dfs(int cur,int sum)
{
	if(cur==k+1)
	{
		if(check(sum))
			ans++;
	}
	else
	{
		for(int i=1;i<=n;i++)
			if(!v[i])
			{
				v[i]=1;
				dfs(cur+1,sum+a[i]);
				v[i]=0;
			}
	}
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[0]=1;
	for(int i=1;i<=k;i++)
		f[i]=f[i-1]*i;
	dfs(1,0);
	cout<<ans/f[k]<<endl;
	return 0;
}
     