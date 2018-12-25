#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
const int MAXM=100005;
struct Edge
{
	int to,next;
}e[MAXM<<1];
int first[MAXN];
int color[MAXN];
int ans1,ans2;
int n,m,tot;
int ans;

inline void Add_Edge(int x,int y)
{
	tot++;
	e[tot].to=y;	e[tot].next=first[x];
	first[x]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
	int x,y,w;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Add_Edge(x,y);
		Add_Edge(y,x);
	}
}

void dfs(int x)
{
	for(int i=first[x];i!=-1;i=e[i].next)
	{
		int u=e[i].to;
		if(color[u]==color[x])
		{
			cout<<"Impossible"<<endl;
			exit(0);
		}
		else	if(!color[u])
		{
			color[u]=3-color[x];
			if(color[u]==1)
				ans1++;
			else
				ans2++;
			dfs(u);
		}
	}
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		if(!color[i])
		{
			color[i]=1;
			ans1=1;	ans2=0;
			dfs(i);
			ans+=min(ans1,ans2);
		}
	cout<<ans<<endl;
	return 0;
}
     