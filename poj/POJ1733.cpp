#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

const int MAXN=20005;
map<int,int> Hash;
int fa[MAXN];
int n,m;
int cnt;

inline int getfather(const int& x)
{
	return fa[x]==x?x:fa[x]=getfather(fa[x]);
}

int getidx(const int& x)
{
	return Hash[x]?Hash[x]:Hash[x]=++cnt;
}

void init()
{
	cin>>n>>m;
	for(int i=1;i<MAXN;i++)
		fa[i]=i;
}

void work()
{
	int u,v;
	string w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		cin>>w;
		int x=getidx(u-1),y=getidx(v);
		int dx=getidx(u-1+MAXN),dy=getidx(v+MAXN);
		if(w=="odd")
		{
			if(getfather(x)==getfather(y)||getfather(dx)==getfather(dy))
			{
				printf("%d\n",i-1);
				return;
			}
			else
			{
				fa[getfather(x)]=getfather(dy);
				fa[getfather(dx)]=getfather(y);
			}
		}
		else
		{
			if(getfather(x)==getfather(dy)||getfather(dx)==getfather(y))
			{
				printf("%d\n",i-1);
				return;
			}
			else
			{
				fa[getfather(x)]=getfather(y);
				fa[getfather(dx)]=getfather(dy);
			}
		}
	}
	printf("%d\n",m);
}

int main()
{
	init();
	work();
	return 0;
}