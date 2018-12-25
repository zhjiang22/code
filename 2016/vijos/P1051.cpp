#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <queue>
using namespace std;

struct node
{
	int x,y;
};
int we;
bool map[102][102];
int n,m;
int ans;
queue<node>	q;

void bfs(int x,int y)
{
	node p;
	p.x=x,p.y=y;
	q.push(p);
	map[x][y]=0;

	while(!q.empty())
	{
		node r=q.front();
		q.pop();

		for(int i=-2;i<=2;i++)
		{
			for(int j=-2;j<=2;j++)
			{
				if(abs(i)+abs(j)>2)
					continue;
				int newx=r.x+i;
				int newy=r.y+j;
				if(newx>=1&&newy>=1&&newy<=m&&newx<=n&&map[newx][newy])
				{
					map[newx][newy]=0;
					node o;
					o.x=newx;
					o.y=newy;
					q.push(o);
				}
			}	
		}
	}
	ans++;
}

int main()
{
	char ch;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='#')
				map[i][j]=1;
			else
				map[i][j]=0;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i][j])
				bfs(i,j);
	cout<<ans<<endl;
	return 0;
}
     