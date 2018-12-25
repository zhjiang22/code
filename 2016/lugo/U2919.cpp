#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[40];
int V,n;
int f[1000005];

int main()
{
	scanf("%d%d",&V,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=V;j>=a[i];j--)
			f[j]=max(f[j],f[j-a[i]]+a[i]);
	printf("%d\n",V-f[V]);
	return 0;
}