#include<bits/stdc++.h>
using namespace std;

const int MAXN=1005;
int a[MAXN];
int f[MAXN];
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
}

void work()
{
	f[1]=a[1];	f[2]=min(a[1],a[2]);
	for(int i=3;i<=n;i++)
		f[i]=min(max(f[i-1],f[i-2]),a[i]);
	printf("%d\n",f[n]);
}

int main()
{
	init();
	work();
	return 0;
}
     