/*
一个标准的最小生成树问题
第一个答案自然就是点数n-1了
第二个答案就应该是加入的最大边权
就是我们加到n-1条边时的最后那条边了~
自然就是最大权值
这样直接一个Kruskal就可以解决问题
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=305;
const int MAXM=MAXN*MAXN;
struct Edge
{
	int x,y,w;
	bool operator<(const Edge& b)const
	{
		return w<b.w;
	}
}e[MAXM];
int fa[MAXN];
int n,m;

inline int find(int& x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	for(int i=1;i<=n;i++)
		fa[i]=i;
}

void Kruskal()
{
	sort(e+1,e+m+1);
	int tot=0,ans;
	for(int i=1;i<=m;i++)
	{
		int& x=e[i].x;	int& y=e[i].y;	int& w=e[i].w;
		int fx=find(x);	int fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			tot++;
			if(tot==n-1)
			{
				ans=w;
				break;
			}
		}
	}
	printf("%d %d\n",tot,ans);
}

int main()
{
	init();
	Kruskal();
}
     