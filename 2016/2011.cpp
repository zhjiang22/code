#include <iostream>
#include <cstdio>
using namespace std;

const int k=10000;
string a;

void powder(int n)
{
	int ans=0;
	int x=2011;
	while(!(n&1))
	{
		x=x*x%k;
		n>>=1;
	}
	ans=x;
	n>>=1;
	while(n)
	{
		x=x*x%k;
		if(n&1)
			ans=ans*x%k;
		n>>=1;
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("D:\\in.txt","r",stdin);
	freopen("D:\\out.txt","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{	cin>>a;
		int x=a.length();
		if(x>=3)
			n=(a[x-1]-'0')+(a[x-2]-'0')*10+(a[x-3]-'0')*100;
		else if(x==2)
			n=(a[x-1]-'0')+(a[x-2]-'0')*10;
		else if(x==1)
			n=(a[x-1]-'0');
		powder(n);
	}
	return 0;
}