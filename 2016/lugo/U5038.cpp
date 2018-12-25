#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=40005;
vector<int> g[MAXN];
bool v[MAXN];
int link[MAXN];
int n;

void init()
{
	cin>>n;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		g[x].push_back(i);
		g[y].push_back(i);
	}
}

bool dfs(int x)
{
	int d=g[x].size();
	for(int i=0;i<d;i++)
	{
		int u=g[x][i];
		if(!v[u])
		{
			v[u]=1;
			if(link[u]==0||dfs(link[u]))
			{
				link[u]=x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	init();
	int i=1;
	for(;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		if(!dfs(i))
			break;
	}
	cout<<i-1<<endl;
	return 0;
}
     