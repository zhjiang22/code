#include<bits/stdc++.h>
using namespace std;

const int MAXN=200005;
struct Edge
{
	int to,nxt;
}e[MAXN<<1];
int first[MAXN];
int tot;
int n;

void Add_Edge(const int& u,const int& v)
{
	e[++tot].to=v;
	e[tot].nxt=first[u];	first[u]=tot;
}

void init()
{
	scanf("%d",&n);
	int x;
	memset(first,-1,sizeof(first));
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		Add_Edge(i,x);	Add_Edge(x,i);
	}
}

int fa[MAXN];

void dfs(int u,int father)
{
	for(int i=first[u];i!=-1;i=e[i].nxt)
	{
		int& v=e[i].to;
		if(v!=father)
			dfs(v,fa[v]=u);
	}
}

int a[MAXN];

void work()
{
	dfs(1,-1);
	int p=0;
	int cur=n;
	while(cur!=0)
	{
		a[++p]=cur;
		cur=fa[cur];
	}
	for(int i=p;i>=1;i--)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	init();
	work();
	return 0;
}