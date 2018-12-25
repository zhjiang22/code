#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
int n,m;

int solve(int x)
{
	int p=1,q=0;
	for(int i=1;i<=n;i++)
		if(q+a[i]<=x)	q+=a[i];
		else	p++,q=a[i];
	return p;	
}

int main()
{
	int l=0,r=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			r+=a[i];
			l=max(l,a[i]);
		}
	while(l<=r)
	{
		int mid=(l+r)/2;
		int x=solve(mid);
		if(x>m)
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}