#include<iostream>
#include<cstring>
using namespace std;

int n,m,k;
int link[101];
bool visit[101];
bool map[101][101];

bool dfs(int x)
{
	for(int i=1;i<=n;i++)
		if(map[x][i]==true&&!visit[i])
		{
			visit[i]=true;
			if(link[i]==0||dfs(link[i]))
			{
				link[i]=x;
				return true;
			}
		}
	return false;
}

int main()
{
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		map[x][y]=true;
	}

	for(int i=1;i<=n;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i))
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}