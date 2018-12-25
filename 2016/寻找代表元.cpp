#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int map[205][205];
int Link[205];
int visit[205];
int n,m,ans;

bool dfs(int x)
{
	for(int i=1;i<=m;i++)
		if(!visit[i]&&map[x][i])
		{
			visit[i]=1;
			if(!Link[i]||dfs(Link[i]))
			{
				Link[i]=x;
				return true;
			}
		}
	return false;
}

int main()
{
	int k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		while(1)
		{
			cin>>k;
			if(k==0)
				break;
			map[i][k]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i))
				ans++;}
	cout<<ans<<endl;
	return 0;
}
     