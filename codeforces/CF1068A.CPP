#include <bits/stdc++.h>
using namespace std;

unsigned long long n,m,k,l;

void init()
{
	cin>>n>>m>>k>>l;
}

void work()
{
	if(m>n||(l+k>n))
	{
		cout<<-1<<endl;
		return;
	}
	unsigned long long p;
	if((l+k)%m==0)
		p=(l+k)/m;
	else
		p=(l+k)/m+1;
	if(p*m>n)
		cout<<-1<<endl;
	else
		cout<<p<<endl;
}

int main()
{
	init();
	work();
	return 0;
}