#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a[50003];
int n;

void check(int x)
{
	if(2*x<=n)
		if(a[2*x]>=a[x])
		{
			cout<<"No"<<endl;
			exit(0);
		}
		else check(2*x);
	if(2*x<n)
		if(a[2*x+1]>=a[x])
		{
			cout<<"No"<<endl;
			exit(0);
		}
		else check(2*x+1);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	check(1);
	cout<<"Yes";
	return 0;
}
     