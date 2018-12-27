#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int n,m;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	int ans=0;
	cin>>n>>m;
	int a=n*m;
	for(int i=2;i<=a;i++)
	{
		if(a%i!=0)
			continue;
		else
		{
			int j=a/i;
			if(gcd(i,j)==n)
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
     