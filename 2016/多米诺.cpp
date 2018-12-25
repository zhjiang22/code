#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int map[2600][2600]={0};
int n,m,k;
int a[53][53]={0};
int Link[62600]={0};
int visit[2600]={0};

void init()
{
	int z[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(!a[i][j])
			{
				int num=(i-1)*m+j;
				for(int q=0;q<4;q++)
				{
					int newx=i+z[q][0];
					int newy=j+z[q][1];
					if(newx>n||newx<1||newy<1||newy>m||a[newx][newy])
						continue;
					int numm=(newx-1)*m+newy;
					map[num][numm]=1;
				}
			}
	}
}

bool dfs(int x)
{
	for(int i=1;i<=n*m;i++)
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
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
	}
	init();
	for(int i=1;i<=n*m;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i))
			ans++;
	}
	cout<<ans/2<<endl;
	return 0;
}
     