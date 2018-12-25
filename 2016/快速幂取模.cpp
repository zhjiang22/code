#include<iostream>
using namespace std;

long long n,m,k;
void powder()
{
	long long ans=1;
	int m2=m;
	int n1=n;
	while(!(m&1))
	{
		n=n*n%k;
		m>>=1;
	} 
	m>>=1;
	ans*=n;
	while(m)
	{
		n=n*n%k;
		if(m&1)
		ans=n*ans%k;
		m>>=1;
	}
	cout<<n1<<"^"<<m2<<" mod "<<k<<"="<<ans%k;
}
int main()
{
	
	cin>>n>>m>>k;
	powder();
	return 0;
} 