#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF=999999999;

struct node
{
	int x,y;
};
int visit[1200][1200]={0};
int zx[5]={0,0,0,1,-1};
int zy[5]={0,1,-1,0,0};
int n,m,x1,y1;
int a[1000][1000];
queue<node> q;

int bfs(int q1,int q2)
{
	int ans=0;
	node o1,o2;
	o1.x=q1,o1.y=q2;
	q.push(o1);
	while(!q.empty())
	{
		o2=q.front();
		q.pop();
		for(int i=1;i<=4;i++)
		{
			int x=o2.x+zx[i];
			int y=o2.y+zy[i];
			if(a[x][y]<=a[o2.x][o2.y]&&visit[x][y]==0)
			{
				ans++;
				q.push(o2);
				visit[x][y]=1;
			}
		}	
	}
	return ans;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		cin>>a[i][j];
	cin>>x1>>y1;
	cout<<(n*m-bfs(x1,y1));
	return 0;	
}