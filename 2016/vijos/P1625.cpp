#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a[10002];
int f[10002];
int C,V,n;

int main()
{
	int v,c;
	cin>>V>>n>>C;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>c;
		for(int j=C;j>=c;j--)
			f[j]=max(f[j],f[j-c]+v);
	}
	for(int i=0;i<=C;i++)
		if(f[i]>=V)
		{
			cout<<C-i<<endl;
			return 0;
		}
	cout<<"Impossible"<<endl;
	return 0;
}
     