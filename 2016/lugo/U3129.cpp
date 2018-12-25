#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

char a[6][6];
bool v[6][6];
int zx[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int ans;
string k;

void init()
{
	cin>>k;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i][j];
}

void dfs(int x,int y)
{
	v[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int newx=x+zx[i][0];
		int newy=y+zx[i][1];
		if(newx<1||newx>5||newy<1||newy>5)
			continue;
		if(!v[newx][newy]&&a[newx][newy]==a[x][y])
		{
			v[newx][newy]=1;
			dfs(newx,newy);
		}
	}
}

int main()
{
	init();
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			if(!v[i][j])
			{
				dfs(i,j);
				ans++;
			}
	cout<<ans<<endl;
	return 0;
}
     