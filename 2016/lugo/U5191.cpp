#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=25;
int f[1005];
int n;
int V;

int main()
{
	double k,k1;
	int b,c;
	cin>>k;	V=k*10;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k>>k1;	b=k*10;	c=k1*10;
		for(int j=V;j>=b;j--)
			f[j]=max(f[j],f[j-b]+c);
	}
	printf("%.1f\n",((double)f[V]/10.0));
	return 0;
}
     