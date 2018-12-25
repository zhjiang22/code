#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

int ans=0;
int n,m,k;
int link[101];
bool visit[101];
bool map[101][101];

bool dfs(int x)
{
	for(int i=1;i<=m;i++)
	{
		if(!visit[i]&&map[x][i])
		{
			visit[i]=true;
			if(!link[i]||dfs(link[i]))
			{
				link[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	memset(link,0,sizeof(link));
	memset(map,false,sizeof(map));
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		map[a][b]=true;
	}
	for(int i=1;i<=n;i++)
	{
		memset(visit,false,sizeof(visit));
		if(dfs(i))
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
     