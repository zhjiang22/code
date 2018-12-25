#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int f[30005];
int n,W;

int main()
{
	int v,w;
	cin>>W>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>w;
		w*=v;
		for(int j=W;j>=v;j--)
			f[j]=max(f[j],f[j-v]+w);
	}
	cout<<f[W]<<endl;
	return 0;
}
     