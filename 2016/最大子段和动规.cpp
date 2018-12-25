#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[100];
int d[100];
int n;

int dp(int x)
{
	if(d[x]!=-1)
		return d[x];
	return d[x]=max(dp(x-1),0)+a[x];
}

int main()
{
	
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	memset(d,-1,sizeof(d));
	d[1]=a[1];
	dp(n);
	int MAX=-111;
	for(int i=1;i<=n;i++)
	MAX=max(MAX,d[i]);
	cout<<MAX;
	return 0;
}