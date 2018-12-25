#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int powder(int x,int n)
{
	while(!(n&1))
	{
		n>>=1;
		x*=x;
	}
	int ans=x;
	while(n)
	{
		n>>=1;
		x*=x;
		if(n&1)
			ans*=x;
	}
	return ans;
}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<powder(n,m)<<endl;
	return 0;
}