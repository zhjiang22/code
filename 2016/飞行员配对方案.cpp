#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int n,m,k;
int Link[102]={0};
int visit[102]={0};
int map[102][102]={0};

bool dfs(int x)
{
	for(int i=n+1;i<=m;i++)
	{
		if(!visit[i]&&map[x][i])
		{
			visit[i]=true;
			if(!Link[i]||dfs(Link[i]))
			{
				Link[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int ans=0;
	cin>>n>>m;
	int i,j;
	while(scanf("%d%d",&i,&j)&&i!=-1)
		map[i][j]=1;
	for(int i=1;i<=m;i++)
		{
			memset(visit,0,sizeof(visit));
			if(dfs(i))
					ans++;}
	cout<<ans<<endl;
	if(ans==0)
	{
		cout<<"No solution!";
		return 0;
	}
	for(int i=n+1;i<=m;i++)
		if(Link[i])
			cout<<Link[i]<<" "<<i<<endl;
	return 0;
}
     