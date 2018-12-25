#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define LL long long
struct flower
{
	LL z,c,v;
}b[3];
struct bag
{
	LL v,w,z;
}a[102];
LL f[8002];
LL n,V;

int main()
{
	cin>>n>>V;
	for(int i=0;i<=2;i++)
		cin>>b[i].z>>b[i].c>>b[i].v;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v>>a[i].z;
		for(int j=0;j<=2;j++)
		{
			if(b[j].z==a[i].z)
			{
				a[i].w=b[j].c*a[i].v;
				a[i].v+=a[i].v*b[j].v;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=V;j>=a[i].v;j--)
			f[j]=max(f[j],f[j-a[i].v]+a[i].w);
	}
	cout<<f[V]<<endl;
	return 0;
}
     