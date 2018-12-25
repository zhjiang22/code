#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int f[10002];
int n,V;
int v,w;

int main()
{
	cin>>n>>V;
	for(int i=1;i<=n;i++)
		{cin>>v>>w;
			for(int j=V;j>=v;j--)
					f[j]=max(f[j],f[j-v]+w);}
	cout<<f[V]<<endl;
	system("pause");
	return 0;
}
     