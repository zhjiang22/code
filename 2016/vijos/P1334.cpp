#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int f[405][405];
int n;
int V,W;

int main()
{
	int w,v,c;
	cin>>V>>W>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>w>>c;
		for(int j=V;j>=v;j--)
		{
			for(int k=W;k>=w;k--)
				f[j][k]=max(f[j][k],f[j-v][k-w]+c);
		}
	}
	cout<<f[V][W]<<endl;
	return 0;
}
     