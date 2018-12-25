#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=1005;
struct node
{
	int x,y;
};
int zx[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int a[MAXN][MAXN];
int d[MAXN][MAXN];
queue<node> q;
int n,m;
int ans;

void init()
{
	char ch;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>ch;
			if(ch=='#')
				a[i][j]=-1;
			else	if(ch=='@')
			{
				a[i][j]=1;
				q.push((node){i,j});
				d[i][j]=1;
			}
		}
	cin>>m;
}

void bfs()
{
	while(!q.empty())
	{
		node u=q.front();	q.pop();
		int x=u.x;	int y=u.y;
		for(int i=0;i<4;i++)
		{
			int newx=x+zx[i][0];
			int newy=y+zx[i][1];
			if(newx<1||newx>n||newy<1||newy>n)
				continue;
			if(a[newx][newy]==0)
			{
				a[newx][newy]=1;
				d[newx][newy]=d[x][y]+1;
				q.push((node){newx,newy});
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(d[i][j]<=m)
				ans++;
	cout<<ans<<endl;
}

int main()
{
	init();
	bfs();
	return 0;
}
     