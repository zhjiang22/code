#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
string a[MAXN][3];
int fa[MAXN];
int g[MAXN];
int ans;
int n;

int find(int& x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		fa[i]=i,g[i]=1;
}

bool check(int i,int j)
{
	int cnt=0;	bool use[3];	memset(use,0,sizeof(use));
	for(int k=0;k<3;k++)
		for(int l=0;l<3;l++)
			if(!use[l]&&a[i][k]==a[j][l])
			{
				use[l]=1;	cnt++;
				break;
			}
	return cnt==3;
}

void work()
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(check(i,j))
			{
				int fx=find(i);	int fy=find(j);
				if(fx!=fy)
				{
					fa[fy]=fx;
					g[fx]+=g[fy];
				}
			}
}

void out()
{
	for(int i=1;i<=n;i++)
		ans=max(ans,g[i]);
	printf("%d\n",ans);
}

int main()
{
	init();
	work();
	out();
}