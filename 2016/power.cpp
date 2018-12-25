#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

unsigned long long power(unsigned long long x,unsigned long long n)
{
	if(n==0||n==1)
	{
		if(n==1) return x;
		else return 1;
	}
	else
	{
		int c=power(x,n/2);
		if(n%2==0)
		return c*c;
		else 
		return c*c*x;
	}
	
}

int main()
{
	freopen("power.in","r",stdin);
  	freopen("power.out","w",stdout);  
	unsigned long long X,n;
	cin>>X>>n;
	cout<<power(X,n);
	return 0;
}