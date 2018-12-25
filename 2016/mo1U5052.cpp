#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int ans;

int main()
{
	cin>>n;
	while(n)
	{
		ans+=n/5;
		n/=5;
	}
	cout<<ans<<endl;
	return 0;
}
     