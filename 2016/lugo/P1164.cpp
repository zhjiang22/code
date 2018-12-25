#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXV=10005;
const int MAXN=105;
int f[MAXV];
int a[MAXN];
int n,V;

void init()
{
	cin>>n>>V;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}

int main()
{
	init();
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=V;j>=a[i];j--)
			f[j]+=f[j-a[i]];
	cout<<f[V]<<endl;
	return 0;
}
     