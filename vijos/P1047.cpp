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
	cin>>n>>m;
	int x=gcd(n,m);
	cout<<n*m/x;
	return 0;
}
     