#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
const int INF=0x7ffff;

struct node
{
	int x,y,w;
	node(int x=0,int y=0,int w=INF):x(x),y(y),w(w){}
}a[50002];
int fa[50002];
int n,e;

int getfather(int x)
{
	return x=fa[x]?x:fa[x]=getfather(fa[x]);
}

int cmp(node a,node b)
{
	return a.w<b.w;
}

void Kruskal()
{
	int ans=0;
	int tot=1;
	for(int i=1;i<=e;i++)
	{
		if(getfather(a[i].x)!=getfather(a[i].y))
		{
			ans+=a[i].w;
			fa[getfather(a[i].x)]=getfather(a[i].y);
			tot++;
		}
		if(tot==n)
			break;
	}
	cout<<ans<<endl;
}

int main()
{
	 for(int i=1;i<=n;i++)
	 	fa[i]=i;
	 cin>>n>>e;
	 for(int i=1;i<=e;i++)
	 	cin>>a[i].x>>a[i].y>>a[i].w;
	 sort(a+1,a+n+1,cmp);
	 Kruskal();
	 return 0;
}
     