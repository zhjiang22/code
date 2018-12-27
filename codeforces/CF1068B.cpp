#include <bits/stdc++.h>
using namespace std;

#define LL long long
int ans;
LL n;

void init()
{
	cin>>n;
}

void work()
{
	int m=sqrt(n+1e-5);
	for(int i=1;i<=m;i++)
		if(n%i==0)
			ans++;
	if((long long)m*m==n)
		printf("%d\n",ans*2-1);
	else
		printf("%d\n",ans<<1);
}

int main()
{
	init();
	work();
	return 0;
}