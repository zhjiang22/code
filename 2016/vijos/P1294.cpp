/*
灌水法深搜，注意边界处理。还需要判断是否曾来过，减少不必要搜索。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int n,m;
char a[502][502];
int zx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y)
{
	if(x>n||x<1||y<1||y>m)
		return;
	if(a[x][y]==1)//此句应在下一句前
		return;
	if(a[x][y]=='0')
		a[x][y]=1;
	if(a[x][y]=='*')
		return;
	for(int i=0;i<4;i++)
	{
		int newx=x+zx[i][0];
		int newy=y+zx[i][1];
			dfs(newx,newy);
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]+1;
	for(int i=1;i<=n;i++)
	{
		
			dfs(i,1);
	
			dfs(i,m);
	}
	for(int i=1;i<=m;i++)
	{
		
			dfs(1,i);

			dfs(n,i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='0')
				ans++;
	cout<<ans<<endl;
	return 0;
}
     