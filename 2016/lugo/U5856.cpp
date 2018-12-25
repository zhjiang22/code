#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int MAXV=205;
int v,n;
int f[MAXV];

int main()
{
	scanf("%d%d",&v,&n);
	int x,y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		for(int j=v;j>=x;j--)
			f[j]=max(f[j],f[j-x]+y);
	}
	printf("%d",f[v]);
	return 0;
}