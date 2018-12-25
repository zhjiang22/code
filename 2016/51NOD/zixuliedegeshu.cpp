#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
const long long MOD=1000000007;
int last[MAXN];
int a[MAXN];
long long f[MAXN];
int n;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
}

void DP()
{
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(!last[a[i]])
			f[i]=(f[i-1]*2)%MOD;
		else
			f[i]=((f[i-1]*2)%MOD-f[last[a[i]]-1]%MOD+MOD)%MOD;
		last[a[i]]=i;
	}
	cout<<f[n]-1<<endl;
}

int main()
{
	init();
	DP();
	return 0;
}
     