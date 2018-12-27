#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
long long a,b;

int main()
{
	scanf("%d",&n);
	long long cur = 0;
	long long yin = 1;
	while(n--)
	{
		long long c,d; 
		scanf("%lld%lld",&c,&d);
		while(cur % c != d % c) 
			cur += yin;
		yin *= c;
	}
	printf("%lld",cur);
	return 0;
}
     