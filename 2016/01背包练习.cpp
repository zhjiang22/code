#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int f[10005];
int n,V;

int main()
{
	freopen("D:\\in.txt","r",stdin);
	freopen("D:\\out.txt","w",stdout);
	int w,v;
	memset(f,0,sizeof(f));
	cin>>n>>V;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>w;
		for(int j=V;j>=v;j--)
			f[j]=max(f[j],f[j-v]+w);
	}
	cout<<f[V]<<endl;
	return 0;
}