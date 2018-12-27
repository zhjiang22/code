#include <bits/stdc++.h>
using namespace std;

const int MAXN=8000005;
map<int,int> Hash;
int fa[MAXN];
int cnt;
int t;
int n;

int getfather(const int& x)
{
	return fa[x]==x?x:fa[x]=getfather(fa[x]);
}

int idx(const int& x)
{
	return Hash.count(x)?Hash[x]:Hash[x]=++cnt;
}

void init()
{
	cnt=0;
	cin>>n;
	Hash.clear();
	for(int i=1;i<=4*n+1;i++)
		fa[i]=i;
}

struct Point
{
	int u,v,w;
	bool operator<(const Point& p)const
	{
		return w>p.w;
	}
}a[MAXN];

void work()
{
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int& u=a[i].u;	int& v=a[i].v;	int& w=a[i].w;
		int x=idx(u);	int y=idx(v);
		if(w)
			fa[getfather(x)]=getfather(y);
		else
		{
			if(getfather(x)==getfather(y))
			{
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
}

int main()
{
	cin>>t;
	while(t--)
	{
		init();
		work();
	}
	return 0;
}