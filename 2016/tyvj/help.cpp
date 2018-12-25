#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=45;
struct node
{
	int x,y,step;
	int ok;
	bool operator <(const node b)const
	{
		if(step==b.step)
			return ok<b.ok;
		return step>b.step;
	}
};
priority_queue<node> q;
int a[MAXN][MAXN];
int zx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,w;
node s,t;

void init()
{
	char ch;
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='#')
				a[i][j]=-1;
		}
	int x,y;
	for(int i=1;i<=w;i++)
	{
		cin>>x>>y;
		q.push((node){x,y,1,0});
	}
	cin>>s.x>>s.y;
	cin>>t.x>>t.y;
	s.step=1;	s.ok=1;
	q.push(s);
}

int bfs()
{
	while(!q.empty())
	{
		node u=q.top();	q.pop();
		int x=u.x;	int y=u.y;
		if(a[t.x][t.y]==-1)
			return -1;
		if(x==t.x&&y==t.y&&u.ok==1)
			return u.step;
		if(u.ok==0)
		{
			a[x][y]=-1;
			for(int i=0;i<4;i++)
			{
				int newx=x+zx[i][0];
				int newy=y+zx[i][1];
				if(a[newx][newy]==-1||newx<1||newx>n||newy<1||newy>m)
					continue;	
				q.push((node){newx,newy,u.step+1,0});
			}
		}
		else
		{
			a[x][y]=-1;
			for(int i=0;i<4;i++)
			{
				int newx=x+zx[i][0];
				int newy=y+zx[i][1];
				if(a[newx][newy]!=0||newx<1||newx>n||newy<1||newy>m)
					continue;
				q.push((node){newx,newy,u.step+1,1});
			}
		}
	}
	return -1;
}

int main()
{
	init();
	int ans=bfs();
	if(ans==-1)
		cout<<"No Ans"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
     