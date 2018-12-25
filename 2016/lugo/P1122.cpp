#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=16005;
struct Edge
{
	int to,next;
}e[MAXN<<1];
int first[MAXN];
int w[MAXN];
int n,tot;
int ans=-(1<<29);

inline void Add_Edge(int& x,int& y)
{
	e[++tot].to=y;	e[tot].next=first[x];	first[x]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		Add_Edge(x,y);	Add_Edge(y,x);
	}
}

int dfs(int u,int fa)
{
	int sum=w[u];
	for(int i=first[u];i!=-1;i=e[i].next)
		if(e[i].to!=fa)
		{
			int& v=e[i].to;
			int p=dfs(v,u);
			sum+=max(p,0);
		}
	ans=max(ans,sum);
	return sum;
}

int main()
{
	init();
	dfs(1,-1);
	cout<<ans<<endl;
	return 0;
}
     