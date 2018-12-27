#include <bits/stdc++.h>
using namespace std;

const int MAXN=5005;
int a[MAXN];
int s[MAXN];
int ans;
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		a[i]-=100;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
}

void work()
{
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(s[j]-s[i-1]>0)
				ans=max(ans,j-i+1);
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}