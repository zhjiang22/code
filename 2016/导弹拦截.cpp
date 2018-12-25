#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a[3005];
int f[3005];
int n=1;

int main()
{
	int x,Max=-10,ans=-10;
	while(cin>>x)
		a[n++]=x,getchar();
	n--;
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
			if(a[i]<=a[j])
				f[i]=max(f[i],f[j]+1);
		Max=max(Max,f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
			if(a[i]>=a[j])
				f[i]=max(f[i],f[j]+1);
		ans=max(ans,f[i]);
	}
	cout<<Max<<","<<ans-1<<endl;
	return 0;
}
     