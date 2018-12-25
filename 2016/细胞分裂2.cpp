#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	freopen("E:\\code\\input.txt","r",stdin);
	freopen("E:\\code\\output.txt","w",stdout);
	int n,k;
	int x=2;
	int ans;
	cin>>n>>k;
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
	return 0;
}