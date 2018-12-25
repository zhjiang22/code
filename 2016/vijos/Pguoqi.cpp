#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=52;
const int INF=0x7fffff;
int r[MAXN];
int b[MAXN];
int w[MAXN];
int n,m;
int ans=INF;

void init()
{
	char ch;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&ch);
			if(ch=='W')
				w[i]++;
			else	if(ch=='B')
				b[i]++;
			else	if(ch=='R')
				r[i]++;
		}
	}
}

void check(int x,int y)
{
	int sum=0;
	for(int i=1;i<=x;i++)
		sum+=(m-w[i]);
	for(int i=x+1;i<=y;i++)
		sum+=(m-b[i]);
	for(int i=y+1;i<=n;i++)
		sum+=(m-r[i]);
	ans=min(ans,sum);
}

int main()
{
	init();
	for(int i=1;i<=n-1;i++)
		for(int j=2;j<n;j++)
			if(i!=j)
				check(i,j);
	cout<<ans<<endl;
	return 0;
}
     