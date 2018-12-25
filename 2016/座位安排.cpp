#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int Link1[40006]={0},Link2[40006]={0};
bool map[4006][20002];
bool visit[20002];
int n;

bool dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!visit[i]&&map[x][i])
		{
			visit[i]=true;
			if(!Link1[i]||dfs(Link1[i]))
			{
				Link1[i]=x;
				return true;
			}
			else if(!Link2[i]||dfs(Link2[i]))
			{
				Link2[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios::
	int ans=0;
	int x,y;
	memset(map,false,sizeof(map));
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		cin>>x>>y;
		map[i][x]=map[i][y]=true;
	}
	for(int i=1;i<=2*n;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i))
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
     
