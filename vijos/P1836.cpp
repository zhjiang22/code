/*
方向推背包，精妙~>3<
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int INF=0x7fff;
double f[5000];
int n;
double T=100.0;

int main()
{
	double t;
	int w;
	cin>>n;
	for(int i=1;i<=5*n;i++)
		f[i]=INF;
	for(int i=1;i<=n;i++)
	{
		cin>>t>>w;
		for(int j=n;j>=w;j--)
			f[j]=min(f[j],f[j-w]+t);
	}
	int ans=0;
	for(int i=n;i>=0;i--)
		if(f[i]<=100)
{			cout<<i<<endl;
		break;}
	return 0;
}
     