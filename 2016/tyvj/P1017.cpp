#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int fa[MAXN];
int n,m;
int ans;

int getfather(int x)
{
	return fa[x]==x?x:fa[x]=getfather(fa[x]);
}

void inline Union(int x,int y)
{
	fa[x]=y;
}

int main()
{
	int x,y;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		int fx=getfather(x);
		int fy=getfather(y);
		if(fx==fy)
			ans++;
		else
			Union(fx,fy);
	}
	cout<<ans<<endl;
	return 0;
}
     