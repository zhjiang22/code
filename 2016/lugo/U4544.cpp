#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=205;
const int MAXM=20005;
struct Edge
{
	int to,next;
	Edge()
	{
		to=next=-1;
	}
}e[MAXM<<1];
int first[MAXN];
int n,m,t;
int tot;
int ans1,ans2;

inline void Add_Edge(int x,int y)
{
	tot++;
	e[tot].to=y;e[tot].next=first[x];first[x]=tot;
}

void init()
{
	int x,y;
	memset(first,-1,sizeof(first));
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Add_Edge(x,y);	Add_Edge(y,x);
	}
}

void dfs(int now,int cur)
{
	if(cur==t)
	{
		if(now==n)
			ans1++;
		ans2++;
		return;
}
	}
	for(int i=first[now];i!=-1;i=e[i].next)
		dfs(e[i].to,cur+1);

int main()
{
	init();
	dfs(1,0);
	double x=(double)ans1/ans2;
	printf("%.5lf\n",x);
	return 0;
}
     