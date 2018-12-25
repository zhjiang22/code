#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int a[1600][1600];
int b[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

struct node 
{
	int x,y;
};
queue<node> q;

int bfs(int x,int y)
{
	node p,z;
	int ans=1;
	p.x=x,p.y=y;
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		a[p.x][p.y]=0;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int x1=p.x+a[i][0];
			int y1=p.y+a[i][1];
			if(a[x][y])
			{
				ans++;
				a[x1][y1]=0;
				z.x=x1;
				z.y=y1;
				q.push(z);
			}
		}
	}
	return ans;
}

int main()
{
	int mi=99999999,ans=0;
	memset(a,0,sizeof(a));
	char x;
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			if(x=='*')
			a[i][j]=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(a[i][j])
		{
			int s3=bfs(i,j);
			ans+=s3;
			mi=min(mi,s3);
		}
		if(((ans-mi)*3)>=s)
		cout<<"Demacia Win!";
		else 
		cout<<"Demacia Lose!";
		return 0;
}