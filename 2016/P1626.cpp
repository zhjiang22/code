#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

const int MAXN=1005;
struct node
{
	int index,low;
	node(int index=-1,int low=-1):index(index),low(low){}
}a[MAXN];
vector<int> g[MAXN];
int n,m;
int SD;
int clock;
int sd[MAXN];
bool v[MAXN];
stack<int> s;

void inline Add_Edge(int u,int v)
{
	g[u].push_back(v);
}

void init()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		Add_Edge(x,y);
	}
}

void dfs(int x)
{
	a[x].index=a[x].low=++clock;
	s.push(x);
	v[x]=1;
	int d=g[x].size();
	for(int i=0;i<d;i++)
	{
		int y=g[x][i];
		if(a[y].index==-1)
		{
			dfs(y);
			a[x].low=min(a[x].low,a[y].low);
		}
		else	if(v[y])
			a[x].low=min(a[x].low,a[y].index);
	}
	if(a[x].low==a[x].index)
	{
		int k;
		SD++;
		do
		{
			k=s.top();
			s.pop();
			sd[k]=SD;
			v[k]=0;
		}
		while(k!=x);
	}
}

void Tarjan()
{
	for(int i=1;i<=n;i++)
		if(a[i].index==-1)
			dfs(i);
}

int main()
{
	init();
	Tarjan();
	cout<<SD<<endl;
}
     