#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long s,a,b,c;
int t;

void init()
{
	cin>>s>>a>>b>>c;
}

void work()
{
	long long k=s/c;
	k/=a;
	long long ans=(s/c);
	ans+=(k*b);
	printf("%I64d\n",ans);
}

int main()
{
	cin>>t;
	while(t--)
	{
		init();
		work();
	}
	return 0;
}