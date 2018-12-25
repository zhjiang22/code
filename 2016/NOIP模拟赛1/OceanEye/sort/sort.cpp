#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n,a[100010],f[100010],maxl,i,j;

int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","r",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	memset(f,0,sizeof(f));
	f[1]=a[1]; maxl=1;
	for(i=2;i<=n;i++)
	{
		if (a[i] >= f[maxl]) f[++maxl] = a[i];
		else
		{
			int pos = lower_bound(f,f+maxl,a[i])-f;
			f[pos]=a[i];
		}
	}
	printf("%d\n",maxl);
	return 0;
}

