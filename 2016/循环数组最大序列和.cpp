#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

long long a[500002];
long long n;
long long sum;
long long ans1=-INT_MAX,ans2=-INT_MAX;

int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
	long long tot=0;
	for(long long i=1;i<=n;i++)
	{
		tot+=a[i];
		if(tot>ans1)
			ans1=tot;
		if(tot<0)
			tot=0;
	}
	for(long long i=1;i<=n;i++)
		a[i]=-a[i];
	tot=0;
	for(long long i=1;i<=n;i++)
	{
		tot+=a[i];
		if(tot>ans2)
			ans2=tot;
		if(tot<0)
			tot=0;
	}
	cout<<max(ans1,sum+ans2)<<endl;
	return 0;
}
   