#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a[55],b[55],u[55];
int n,k,cost,c,v,f,s=0;

int main()
{
	cin>>n>>k>>cost;
	for(int i=1;i<=n;i++)
	{
		cin>>c>>v;
		if(v<=cost)
			f=i;
		if(f>=u[c])
			b[c]=a[c];
		s+=b[c];
		a[c]++;
		u[c]=i;
	}
	cout<<s<<endl;
	return 0;
}
     