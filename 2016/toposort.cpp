#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int map[200][200];
int toppo[200];
int v[200];
int n,m,t;

bool dfs(int u)
{
	v[u]=-1;
	for(int i=1;i<=n;i++)
		if(map[u][i])
		{
			if(v[i]<0)
				return false;
			else if(!v[i]&&!dfs(i))
				return false;
		}
	v[u]=1;
	toppo[t--]=u;
	return true;
}

bool topposort()
{
	t=n;
	for(int i=1;i<=n;i++)
		if(!v[i])
			if(!dfs(i))
				return false;
	return true;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		map[x][y]=1;
	}
	topposort();
	for(int i=1;i<=n;i++)
		cout<<toppo[i]<<endl;
	return 0;
}
     