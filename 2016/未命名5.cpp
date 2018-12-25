#include<iostream>
using namespace std;

int mod(int a,int n,int m)
{
	if(n==1)
	return 1;
	else
	{
	int ans;
	while(!(n&1))
	{
		a=(a*a)%m;
		n>>=1;
	}
	ans=a;
	n>>=1;
	while(n)
	{
		a=(a*a)%m;
		if(n&1)
		ans=(ans*a)%m;
		n>>=1;
	}  
	return ans;
	}
}

int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	cout<<mod(x,y,z);
	return 0;
}