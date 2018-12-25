#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
int f[MAXN];
int n,m;

void init()
{
	scanf("%d%d",&m,&n);
}

void DP()
{
	int w;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w);
		cout<<w<<endl;
		for(int j=m-1;j>=0;j--)
			f[j]=max(f[j],f[((j-w)%m+m)%m]+w);
	}
	for(int i=0;i<m;i++)
		cout<<f[i]<<" ";
	cout<<endl;
	printf("%d\n",f[0]);
}

int main()
{
	init();
	DP();
}
     