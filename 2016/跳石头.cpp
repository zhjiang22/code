#include<iostream>
using namespace std;
int L,n,m;
int a[50002];

int p(int x)
{
	int p=0,q=0;
	for(int i=1;i<=n;i++)
	if(a[i]-p<x)	q++;
	else p=a[i];
	return q;
}

int main()
{
	cin>>L>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	a[++n]=L;
	int l=0,r=L;
	int ans=-111;
	while(l<=r)
	{
		int mid=(l+r)/2;
		int x=p(mid);
		if(x<=m)
		l=mid+1,ans=mid;
		else
		r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}