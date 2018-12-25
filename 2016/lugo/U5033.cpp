#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long a[10]={6,2,5,5,4,5,6,3,7,6};
long long n,m;

long long getn(long long x)
{
	long long ans=0;
	while(x)
	{
		ans+=a[x%10];
		x/=10;
	}
	return ans;
}

int main()
{
	cin>>n>>m;
	for(long long i=100000;i>=1;i--)
		if(getn(m*i)<=n)
		{
			cout<<m*i<<endl;
			return 0;
		}
	cout<<-1<<endl;
	return 0;
}
     