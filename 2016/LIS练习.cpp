#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int f[50001];
int a[50001];
int n,ans=1;

int find(int key)
{
	int l=1,r=ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[f[mid]]<key)
			l=mid+1;
		else
			r=mid-1;
	}
	return l-1;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[f[ans]])
			f[++ans]=i;
		else
		{
			int x=find(a[i]);
			f[x+1]=i;
		}
	}
	cout<<ans<<endl;
	system("pause");
	return 0;
}
     