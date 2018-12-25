#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

void powder(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x/5;
		x/=5;
	}
	cout<<ans;
}

int main()
{
	 int n;
	 cin>>n;
	 powder(n);
	 return 0;
}
     