#include<iostream>
using namespace std;

int powder(int n,int m)
{
	if(n==1||m==1||n==0)
	return 1;
	else if(m>n)
	return powder(n,n);
	else 
	return	powder(n-m,m)+powder(n,m-1);
}

int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<powder(n,m)<<endl;
	}
	return 0;
}