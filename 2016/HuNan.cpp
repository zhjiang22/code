#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

char a[22][22];
char p[6]="HUNAN";
int z[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n;
int ans=0;

void dfs(int x,int y,int step)
{
	if(step==5)
		ans++;
	else
	{
		for(int i=0;i<4;i++)
		{
			int newx=x+z[i][0];
			int newy=y+z[i][1];
			if(newx<=n&&newx>=1&&newy<=n&&newy>=1&&a[newx][newy]==p[step])
				dfs(newx,newy,step+1);
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(a[i][j]=='H')
		dfs(i,j,1);
	cout<<ans<<endl;
	return 0;
}
     