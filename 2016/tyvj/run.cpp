#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

const int MAXN=205;
const int MAXM=40005;
struct Edge
{
	int to,next,w;
	Edge()
	{
		to=next=-1;
		w=0;
	}
}e[MAXM<<1];
int n,m;
int c,s,t,tot;
int first[MAXN];
int can[MAXN];

inline void Add_Edge(int x,int y,int w)
{
	tot++;
	e[tot].to=y;	e[tot].w=w;
	e[tot].next=first[x];	first[x]=tot;
}

void init()
{
	int x,y,w;
	cin>>n>>m>>s>>t>>c;
	memset(first,-1,sizeof(first));
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		Add_Edge(x,y,w);
		Add_Edge(y,x,w);
	}
}

void dfs(int x,int k)
{
	can[x]=1;
	for(int i=first[x];i!=-1;i=e[i].next)
	{
		int to=e[i].to;	int w=e[i].w;
		if(w<=k&&!can[to])
			dfs(to,k);
	}
}

bool check(int x)
{
	memset(can,0,sizeof(can));
	dfs(s,x);
	if(can[t]==1)
		return true;
	else
		return false;
}

int main()
{
	clock_t s=clock();
	init();
	int l=0,r=c;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	if(l==c+1)
		cout<<"Fe Oier"<<endl;
	else
		cout<<l<<endl;
	cout<<(double)(clock()-s)/CLOCKS_PER_SEC<<endl;
	return 0;
}
     