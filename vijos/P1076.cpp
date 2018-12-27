/*
bfs,添加v数组判重减少搜索量，51、52行为核心判断语句，
判断是否有船挨在一起，即是否能构成一个规则方形，若不能直接输出；
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
	int x,y;
	node(int x,int y):x(x),y(y){}
};
int n,m;
int v[1002][1002];
int a[1002][1002];
int ans,bad;
int xy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
queue<node> q;

void bfs(int x,int y)
{
	int tot=0;
	node e(x,y);
	v[x][y]=1;
	q.push(e);
	int x1=x,x2=x,y1=y,y2=y;
	while(!q.empty())
	{
		node r=q.front();
		q.pop();
		tot++;
		for(int i=0;i<4;i++)
		{
			int zx=r.x+xy[i][0];
			int zy=r.y+xy[i][1];
			if(a[zx][zy]&&!v[zx][zy]&&zx<=n&&zx>=1&&zy<=m&&zy>=1)
			{
				node p(zx,zy);
				v[zx][zy]=1;
				q.push(p);
				x1=max(x1,zx);	x2=min(x2,zx);
				y1=max(y1,zy);	y2=min(y2,zy);
			}
		}
	}
	if((x1-x2+1)*(y1-y2+1)!=tot)
		bad=1;
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
				a[i][j]=1;
		}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		if(!v[i][j]&&a[i][j])
		{
			ans++;
			bfs(i,j);
			if(bad)
			{
				cout<<"Bad placement."<<endl;
				return 0;
			}
		}
	}
	cout<<"There are "<<ans<<" ships."<<endl;
	return 0;
}
     